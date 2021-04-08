#include "htab_private.h"
#include <stdlib.h>

void htab_clear(htab_t * t){
    for(size_t i = 0; i < t->arr_size; i++){
        htab_item_t *item = t->items[i];
        t->items[i] = NULL;
        while(item){
            htab_item_t *next_item = item->next;
            free((char*)item->pair.key);
            free(item);
            item = next_item;
        }
    }
    t->size = 0;
}
