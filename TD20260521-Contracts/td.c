#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "chained_list.h"

#define DEFAULT_FILE "contracts.csv"

/* ------------------------------------------------------------------ */
/*  Input helpers                                                       */
/* ------------------------------------------------------------------ */

static void flush_stdin(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

static element read_contract(void)
{
    element e;

    printf("  Ticker           : ");
    scanf("%7s", e.ticker);
    flush_stdin();

    printf("  PUT(0) or CALL(1): ");
    scanf("%d", (int*)&e.type);
    flush_stdin();

    printf("  Quantity         : ");
    scanf("%d", &e.qty);
    flush_stdin();

    printf("  Strike           : ");
    scanf("%lf", &e.strike);
    flush_stdin();

    printf("  Expiration       : ");
    scanf("%11s", e.expiration);
    flush_stdin();

    printf("  Premium          : ");
    scanf("%lf", &e.premium);
    flush_stdin();

    return e;
}

/* ------------------------------------------------------------------ */
/*  Menu                                                                */
/* ------------------------------------------------------------------ */

static void print_menu(void)
{
    printf("\n=== Options Contract Manager ===\n");
    printf("  1. Display list\n");
    printf("  2. Add contract at end\n");
    printf("  3. Remove contract by position\n");
    printf("  4. Save to file\n");
    printf("  5. Load from file\n");
    printf("  0. Quit\n");
    printf("Choice: ");
}

/* ------------------------------------------------------------------ */
/*  Main                                                                */
/* ------------------------------------------------------------------ */

int main(void)
{
    chained_list l = list_init();
    int choice;

    do
    {
        print_menu();
        scanf("%d", &choice);
        flush_stdin();

        switch (choice)
        {

        case 1:
            printf("\n--- Contract list (%zu element(s)) ---\n", l.count);
            list_display(l);
            break;

        case 2:
        {
            printf("\nNew contract:\n");
            element e = read_contract();
            if (list_insert_elem(&l, l.count, e) == 0)
                printf("Contract appended (position %zu).\n", l.count - 1);
            break;
        }

        case 3:
        {
            if (list_is_empty(l))
            {
                printf("List is empty.\n");
                break;
            }
            printf("Remove at position (0-%zu): ", l.count - 1);
            size_t pos;
            scanf("%zu", &pos);
            flush_stdin();
            list_remove_elem(&l, pos);
            break;
        }

        case 4:
        {
            char fname[64] = DEFAULT_FILE;
            printf("Filename [%s]: ", DEFAULT_FILE);
            char buf[64];
            if (fgets(buf, sizeof(buf), stdin) && buf[0] != '\n')
            {
                buf[strcspn(buf, "\n")] = '\0';
                strncpy(fname, buf, sizeof(fname) - 1);
            }
            list_save(l, fname);
            break;
        }

        case 5:
        {
            char fname[64] = DEFAULT_FILE;
            printf("Filename [%s]: ", DEFAULT_FILE);
            char buf[64];
            if (fgets(buf, sizeof(buf), stdin) && buf[0] != '\n')
            {
                buf[strcspn(buf, "\n")] = '\0';
                strncpy(fname, buf, sizeof(fname) - 1);
            }
            list_load(&l, fname);
            break;
        }

        case 0:
            printf("Goodbye.\n");
            break;

        default:
            printf("Unknown option.\n");
        }

    } while (choice != 0);

    list_free(&l);
    return 0;
}
