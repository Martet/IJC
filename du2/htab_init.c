#include <stdlib.h>
#include <string.h>
#include "htab.h"
#include "htab_private.h"

htab_t *htab_init(size_t n){
    htab_t *new_htab = malloc(sizeof(htab_t) + n * sizeof(htab_item_t*));
    if (new_htab == NULL)
        return NULL;
    new_htab->arr_size = n;
    new_htab->size = 0;
    for (size_t i = 0; i < n; i++){
        new_htab->items[i] = NULL;
    }
    return new_htab;
}
