// htab_bucket_count.c
// Řešení IJC-DU2, 2. úkol, 8.4.2021
// Autor: Martin Zmitko, xzmitk01
// Přeloženo: gcc 9.3

#include "htab_private.h"

//returns count of available buckets (htab size)
size_t htab_bucket_count(const htab_t * t){
    return t->arr_size;
}
