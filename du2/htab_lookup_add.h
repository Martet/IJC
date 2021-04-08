// htab_lookup_add.h
// Řešení IJC-DU2, 2. úkol, 8.4.2021
// Autor: Martin Zmitko, xzmitk01
// Přeloženo: gcc 9.3

#include "htab_private.h"

//returns an item from htab, if it already exists with key or creates a new one with key
htab_pair_t * htab_lookup_add(htab_t * t, htab_key_t key);
