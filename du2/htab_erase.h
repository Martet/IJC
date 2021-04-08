// htab_erase.h
// Řešení IJC-DU2, 2. úkol, 8.4.2021
// Autor: Martin Zmitko, xzmitk01
// Přeloženo: gcc 9.3

#include "htab_private.h"

//erases an item with given key form htab t, returns true on success, false if nothing erased
bool htab_erase(htab_t * t, htab_key_t key);
