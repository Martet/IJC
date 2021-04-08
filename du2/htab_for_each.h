// htab_for_each.h
// Řešení IJC-DU2, 2. úkol, 8.4.2021
// Autor: Martin Zmitko, xzmitk01
// Přeloženo: gcc 9.3

#include "htab_private.h"

void htab_for_each(const htab_t * t, void (*f)(htab_pair_t *data));
