// htab_move.h
// Řešení IJC-DU2, 2. úkol, 8.4.2021
// Autor: Martin Zmitko, xzmitk01
// Přeloženo: gcc 9.3

#include "htab_private.h"

//moves items from one htab to a new one of size n, which is returned
htab_t *htab_move(size_t n, htab_t *from); 
