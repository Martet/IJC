#include <stdlib.h>
#include <string.h>
#include "htab_private.h"

htab_t *htab_init(size_t size){
    htab_t *new_htab = malloc(sizeof(htab_t) + size * sizeof(htab_item_t*));
    if (new_htab = NULL)
        return NULL;
    new_htab->arr_size = size;
    new_htab->size = 0;
    for (int i = 0; i < size; i++){
        new_htab->items[i] = NULL;
    }
    return new_htab;
}
