#include "htab_private.h"
#include <stdlib.h>

htab_pair_t * htab_lookup_add(htab_t * t, htab_key_t key){
    htab_pair_t *pair = htab_find(t, key);
    if(pair)
        return pair;

    htab_item_t *new_item = malloc(sizeof(htab_item_t));
    if(new_item == NULL)
        return NULL;

    size_t index = htab_hash_function(key) % htab_bucket_count(t);
    htab_item_t *save_index = t->items[index];
    if(save_index == NULL)
        t->items[index] = new_item;
    else{
        htab_item_t *next_item = save_index->next;
        while(next_item){
            save_index = next_item;
            next_item = save_index->next;
        }
        save_index->next = new_item;
    }
    
    new_item->pair = (htab_pair_t) {.key = key, .value = 0};
    new_item->next = NULL;
    t->size++;

    return &new_item->pair;
}
