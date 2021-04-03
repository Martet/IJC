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
