#include "htab_private.h"

size_t htab_bucket_count(const htab_t * t){
    return t->arr_size;
}
