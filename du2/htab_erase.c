// htab_erase.c
// Řešení IJC-DU2, 2. úkol, 8.4.2021
// Autor: Martin Zmitko, xzmitk01
// Přeloženo: gcc 9.3

#include "htab_private.h"
#include <stdlib.h>

bool htab_erase(htab_t * t, htab_key_t key){
    size_t index = htab_hash_function(key) % htab_bucket_count(t);
    htab_item_t *next = t->items[index];
    if(next == NULL)
        return false; //nothing in bucket

    if(strcmp(next->pair.key, key) == 0){ //if first item matches
        t->items[index] = t->items[index]->next; //set first pointer to next item
        free((char*)next->pair.key);
        free(next); //free item
        t->size--;
        return true;
    }
    htab_item_t *before = next;
    next = next->next;
    while(next){ //loop through rest of items
        if(strcmp(next->pair.key, key) == 0){
            before->next = next->next; 
            free((char*)next->pair.key);
            free(next);
            t->size--;
            return true;
        }
        before = next;
        next = next->next;
    }
    return false;
}
