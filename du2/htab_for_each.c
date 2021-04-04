#include "htab_private.h"

void htab_for_each(const htab_t * t, void (*f)(htab_pair_t *data)){
    for(size_t i = 0; i < t->arr_size; i++){
        htab_item_t *item = t->items[i];
        while(item){
            (*f)(&item->pair);
            item = item->next;
        }
    }
}
