 #include "table_list_fixed_size.h"

list init(void) {
    list l;
    l.count=0;
    return l;
}

bool is_empty(const list l) {
    return l.count==0;
}

bool is_full(const list l) {
    return l.count==LIST_SIZE;
}

int insert(list *l, const size_t pos, const element e) {
    // INFO: return 0 if OK, else -1

    // check if list not full
    if(is_full(*l)) {
        return -1;
    }

    // check if pos coherent
    if(pos>l->count) {
        return -2;
    }

    // case list empty
    if(is_empyt(*l)) {
        memcpy( &(l->t[0]), &e, sizeof(element));
        // memcpy( l->t, &e, sizeof(element));
        
        l->count++;
        return 0;
    }
    // case list not empty
    // move of cells (backward)
    // copy e at pos

    // update count


}