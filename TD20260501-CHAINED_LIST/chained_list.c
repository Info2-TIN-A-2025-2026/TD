#include "chained_list.h"

chained_list list_init()
{
    chained_list l;
    l.first = NULL;
    l.last = NULL;
    l.count = 0;
    return l;
}
int list_insert_elem(chained_list *l, const size_t pos, const element e)
{
    // check if pos coherent
    if (pos > l->count)
    {
        printf("Error, pos %zu incorrect\n", pos);
        return -2;
    }

    // node *n = (node*) malloc( sizeof(node) );
    // n->next=NULL;
    // n->prev=NULL;
    // memcpy( &(n->payload), &e, sizeof(element));

    // déportez les 4 lignes ci-dessus dans un module node.c / node.h
    // fonction : create_node
    node *n = NULL;
    create_node(e, &n);

    if(l->count==0) // list is empty
    {
        l->first = n;
        l->last = n;
        l->count++;
        n->next = NULL;
        n->prev = NULL;
        return 0;
    }
    // list not empty
    if(0==pos) {
        // node *tmp = l->first;
        // tmp->prev = n;
        l->first->prev=n;
        n->next = l->first;
        n->prev = NULL;
        l->first = n;
        l->count++;
        return 0;
    }
    if(pos==l->count) {
        l->last->next = n;
        n->next = NULL;
        n->prev = l->last;
        l->last = n;
        l->count++;
        return 0;
    }
    node *nn = l->first;
    node *np = NULL;
    for (size_t index=0;index<pos;index++) {
        nn=nn->next;
    }
    np=nn->prev;
    np->next=n;
    nn->prev=n;
    n->next=nn;
    n->prev=np;
    l->count++;
    return 0;
}

int get_elem(chained_list l, const size_t pos, const element *e) {
    // for loop from first, pos iterations
    // memcopy of payload in e
}


int list_remove_elem(chained_list l, const size_t pos) {
}
