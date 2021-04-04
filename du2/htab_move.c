#include "htab_private.h"

htab_t *htab_move(size_t n, htab_t *from){
    htab_t *new_tab = htab_init(n);
    if(new_tab == NULL)
        return NULL;
    for(size_t i = 0; i < from->arr_size; i++){
        htab_item_t *item = from->items[i];
        while(item){
            htab_pair_t *pair = htab_lookup_add(new_tab, item->pair.key);
            if(pair == NULL){
                htab_free(new_tab);
                return NULL;
            }
            pair->value = item->pair.value;
            item = item->next;
        }
    }
    htab_clear(from);
    return new_tab;
}
