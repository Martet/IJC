// htab_find.c
// Řešení IJC-DU2, 2. úkol, 8.4.2021
// Autor: Martin Zmitko, xzmitk01
// Přeloženo: gcc 9.3

#include "htab_private.h"

htab_pair_t * htab_find(htab_t * t, htab_key_t key){
    size_t index = htab_hash_function(key) % htab_bucket_count(t);
    htab_item_t *next = t->items[index];
    while(next){
        if(strcmp(next->pair.key, key) == 0)
            return &next->pair;
        next = next->next;
    }
    return NULL;
}
