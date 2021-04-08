// htab_find.h
// Řešení IJC-DU2, 2. úkol, 8.4.2021
// Autor: Martin Zmitko, xzmitk01
// Přeloženo: gcc 9.3

#include "htab_private.h"

//returns a htab pair pointer if key was found, else returns NULL
htab_pair_t * htab_find(htab_t * t, htab_key_t key);
