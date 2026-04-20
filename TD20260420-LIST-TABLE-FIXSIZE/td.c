#include <stdio.h>
#include "table_list_fixed_size.h"

int main(int argc, const char *argv[])
{
    list l;
    l=init();
    
    printf("l is empty=%s\n", is_empty(l)?"YES":"NO");
    printf("l is full=%s\n", is_full(l)?"YES":"NO");

    // printf("l.count=%lu\n", l.count);
    // for(size_t i=0;i<LIST_SIZE;i++) {
    //     printf("%lu %+6.3lf\n", i, l.t[i]);
    // }
    return 0;
}