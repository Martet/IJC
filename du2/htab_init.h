// htab_init.h
// Řešení IJC-DU2, 2. úkol, 8.4.2021
// Autor: Martin Zmitko, xzmitk01
// Přeloženo: gcc 9.3

#include "htab_private.h"

//dynamically initializes a new hash table with n buckets
htab_t *htab_init(size_t n);
