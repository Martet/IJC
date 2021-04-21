// htab_move.c
// Řešení IJC-DU2, 2. úkol, 8.4.2021
// Autor: Martin Zmitko, xzmitk01
// Přeloženo: gcc 9.3

#include "htab_private.h"

//moves items from one htab to a new one of size n, which is returned
htab_t *htab_move(size_t n, htab_t *from){
    //innit and check new htab
    htab_t *new_tab = htab_init(n);
    if(new_tab == NULL)
        return NULL;

    //for each item in htab
    for(size_t i = 0; i < from->arr_size; i++){
        htab_item_t *item = from->items[i];
        while(item){
            //add item to new htab and check if valid
            htab_pair_t *pair = htab_lookup_add(new_tab, item->pair.key);
            if(pair == NULL){
                htab_free(new_tab);
                return NULL;
            }
            pair->value = item->pair.value;
            item = item->next;
        }
    }
    //delete all items from source htab
    htab_clear(from);
    return new_tab;
}
