// htab_private.h
// Řešení IJC-DU2, 2. úkol, 8.4.2021
// Autor: Martin Zmitko, xzmitk01
// Přeloženo: gcc 9.3

#include "htab.h"

typedef struct htab_item{
    struct htab_item *next;
    htab_pair_t pair;
} htab_item_t;

struct htab {
    size_t size;
    size_t arr_size;
    htab_item_t *items[];
};
