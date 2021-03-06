// htab_free.c
// Řešení IJC-DU2, 2. úkol, 8.4.2021
// Autor: Martin Zmitko, xzmitk01
// Přeloženo: gcc 9.3

#include "htab_private.h"
#include <stdlib.h>

//removes all items from htab and frees it
void htab_free(htab_t * t){
    htab_clear(t);
    free(t);
}
