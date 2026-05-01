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

    node *n = (node*) malloc( sizeof(node) );
    n->next=NULL;
    n->prev=NULL;
    memcpy( &(n->payload), &e, sizeof(element));

    // déportez les 4 lignes ci-dessus dans un module node.c / node.h
    // fonction : create_node

   
    return
}
