// htab_clear.c
// Řešení IJC-DU2, 2. úkol, 8.4.2021
// Autor: Martin Zmitko, xzmitk01
// Přeloženo: gcc 9.3

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
