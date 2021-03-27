// bitset.c
// Řešení IJC-DU1, příklad a), 23.3.2021
// Autor: Martin Zmitko, xzmitk01
// Přeloženo: gcc 9.3

#include "bitset.h"

#ifdef USE_INLINE

extern void bitset_free(bitset_t name);

extern bitset_index_t bitset_size(bitset_t name);

extern void bitset_setbit(bitset_t name, bitset_index_t index, int value);

extern int bitset_getbit(bitset_t name, bitset_index_t index);

#endif