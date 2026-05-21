#include "chained_list.h"
#include <stdlib.h>
#include <string.h>

/* ------------------------------------------------------------------ */
/*  Lifecycle                                                           */
/* ------------------------------------------------------------------ */

chained_list list_init(void) {
    chained_list l;
    l.first = NULL;
    l.last  = NULL;
    l.count = 0;
    return l;
}

void list_free(chained_list *l) {
    node *cur = l->first;
    while (cur) {
        node *next = cur->next;
        free_node(cur);
        cur = next;
    }
    l->first = NULL;
    l->last  = NULL;
    l->count = 0;
}

/* ------------------------------------------------------------------ */
/*  Queries                                                             */
/* ------------------------------------------------------------------ */

bool list_is_empty(chained_list l) {
    return l.count == 0;
}

/* Returns a pointer to the node at position pos, or NULL if invalid. */
static node *node_at(chained_list l, size_t pos) {
    if (pos >= l.count) return NULL;
    node *cur = l.first;
    for (size_t i = 0; i < pos; i++)
        cur = cur->next;
    return cur;
}

int list_get_elem(chained_list l, size_t pos, element *e) {
    if (list_is_empty(l)) {
        printf("Error: list is empty\n");
        return -1;
    }
    node *n = node_at(l, pos);
    if (!n) {
        printf("Error: pos %zu out of range\n", pos);
        return -2;
    }
    memcpy(e, &(n->payload), sizeof(element));
    return 0;
}

/* ------------------------------------------------------------------ */
/*  Insert                                                              */
/* ------------------------------------------------------------------ */

int list_insert_elem(chained_list *l, size_t pos, element e) {
    if (pos > l->count) {
        printf("Error: pos %zu out of range\n", pos);
        return -2;
    }

    node *n = NULL;
    if (create_node(e, &n) != 0) {
        printf("Error: malloc failed\n");
        return -1;
    }

    /* --- empty list --- */
    if (l->count == 0) {
        l->first = n;
        l->last  = n;
        l->count++;
        return 0;
    }

    /* --- insert at head --- */
    if (pos == 0) {
        n->next        = l->first;
        l->first->prev = n;
        l->first       = n;
        l->count++;
        return 0;
    }

    /* --- insert at tail --- */
    if (pos == l->count) {
        n->prev       = l->last;
        l->last->next = n;
        l->last       = n;
        l->count++;
        return 0;
    }

    /* --- insert in middle --- */
    node *nn = node_at(*l, pos);   /* node currently at pos   */
    node *np = nn->prev;           /* node just before pos    */

    np->next = n;
    nn->prev = n;
    n->prev  = np;
    n->next  = nn;
    l->count++;
    return 0;
}

/* ------------------------------------------------------------------ */
/*  Remove                                                              */
/* ------------------------------------------------------------------ */

int list_remove_elem(chained_list *l, size_t pos) {
    if (list_is_empty(*l)) {
        printf("Error: list is empty\n");
        return -1;
    }
    if (pos >= l->count) {
        printf("Error: pos %zu out of range\n", pos);
        return -2;
    }

    node *n = node_at(*l, pos);

    /* re-wire neighbours */
    if (n->prev) n->prev->next = n->next;
    else         l->first      = n->next;   /* removed head */

    if (n->next) n->next->prev = n->prev;
    else         l->last       = n->prev;   /* removed tail */

    free_node(n);
    l->count--;
    return 0;
}

/* ------------------------------------------------------------------ */
/*  Display                                                             */
/* ------------------------------------------------------------------ */

void list_display(chained_list l) {
    if (list_is_empty(l)) {
        printf("  (list is empty)\n");
        return;
    }
    node *cur = l.first;
    size_t i  = 0;
    while (cur) {
        printf("[%zu] ", i++);
        display_element(cur->payload);
        cur = cur->next;
    }
}

/* ------------------------------------------------------------------ */
/*  Persistence  (CSV: ticker,qty,strike,expiration,premium)           */
/* ------------------------------------------------------------------ */

int list_save(chained_list l, const char *filename) {
    FILE *f = fopen(filename, "w");
    if (!f) {
        printf("Error: cannot open '%s' for writing\n", filename);
        return -1;
    }

    node *cur = l.first;
    while (cur) {
        element *e = &(cur->payload);
        fprintf(f, "%s,%d,%d,%.2f,%s,%.2f\n",
                e->ticker,
                e->type,
                e->qty,
                e->strike,
                e->expiration,
                e->premium);
        cur = cur->next;
    }

    fclose(f);
    printf("Saved %zu contract(s) to '%s'\n", l.count, filename);
    return 0;
}

int list_load(chained_list *l, const char *filename) {
    FILE *f = fopen(filename, "r");
    if (!f) {
        printf("Error: cannot open '%s' for reading\n", filename);
        return -1;
    }

    /* discard current list */
    list_free(l);
    *l = list_init();

    element e;
    char line[128];
    while (fgets(line, sizeof(line), f)) {
        /* skip blank lines */
        if (line[0] == '\n' || line[0] == '\r') continue;

        int matched = sscanf(line, "%7[^,],%d,%d,%lf,%11[^,],%lf",
                             e.ticker,
                             (int*)&e.type,
                             &e.qty,
                             &e.strike,
                             e.expiration,
                             &e.premium);
        if (matched == 6) {
            list_insert_elem(l, l->count, e);   /* append */
        } else {
            printf("Warning: skipped malformed line: %s", line);
        }
    }

    fclose(f);
    printf("Loaded %zu contract(s) from '%s'\n", l->count, filename);
    return 0;
}
