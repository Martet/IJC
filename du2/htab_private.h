#ifndef __HTAB_PRIVATE_H__
#define __HTAB_PRIVATE_H__

#include <string.h>
#include "htab.h"

struct htab {
    size_t size;
    size_t arr_size;
    htab_item_t *items[];
};

typedef struct htab_item{
    htab_item_t *next;
    htab_pair_t pair;
} htab_item_t;

#endif
