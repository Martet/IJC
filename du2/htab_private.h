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
