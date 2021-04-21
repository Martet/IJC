// htab_lookup_add.c
// Řešení IJC-DU2, 2. úkol, 8.4.2021
// Autor: Martin Zmitko, xzmitk01
// Přeloženo: gcc 9.3

#include "htab_private.h"
#include <stdlib.h>

//returns an item from htab, if it already exists with key or creates a new one with key
htab_pair_t * htab_lookup_add(htab_t * t, htab_key_t key){
    //return pair if it already exists
    htab_pair_t *pair = htab_find(t, key);
    if(pair)
        return pair;
        
    //innit and check new item
    htab_item_t *new_item = malloc(sizeof(htab_item_t));
    if(new_item == NULL)
        return NULL;

    //get index
    size_t index = htab_hash_function(key) % htab_bucket_count(t);
    htab_item_t *save_index = t->items[index];
    if(save_index == NULL) //if no items in bucket, add as first
        t->items[index] = new_item;
    else{ //there are items in bucket
        htab_item_t *next_item = save_index->next;
        while(next_item){ //loop to the end of liked list
            save_index = next_item;
            next_item = save_index->next;
        }
        save_index->next = new_item; //save new item to the end
    }

    //alloc key string
    char *keyptr = malloc(strlen(key) + 1);
    if(keyptr == NULL){
        free(new_item);
        return NULL;
    }
    strcpy(keyptr, key);    

    //save new pair
    new_item->pair = (htab_pair_t) {.key = keyptr, .value = 0};
    new_item->next = NULL;
    t->size++;

    return &new_item->pair;
}
