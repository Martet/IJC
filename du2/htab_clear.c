// htab_clear.c
// Řešení IJC-DU2, 2. úkol, 8.4.2021
// Autor: Martin Zmitko, xzmitk01
// Přeloženo: gcc 9.3

#include "htab_private.h"
#include <stdlib.h>

//removes all items from htab t
void htab_clear(htab_t * t){
    for(size_t i = 0; i < t->arr_size; i++){ //loop through buckets
        htab_item_t *item = t->items[i];
        t->items[i] = NULL; //set first pointer to NULL (all other items lost)
        while(item){ //loop through all items in bucket
            htab_item_t *next_item = item->next;
            free((char*)item->pair.key);
            free(item); //free every item
            item = next_item;
        }
    }
    t->size = 0;
}
