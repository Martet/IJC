// eratosthenes.c
// Řešení IJC-DU1, příklad a), 23.3.2021
// Autor: Martin Zmitko, xzmitk01
// Přeloženo: gcc 9.3

#include <math.h>
#include <string.h>
#include "eratosthenes.h"

void eratosthenes(bitset_t set){
    bitset_index_t i = 2;
    bitset_setbit(set, 1, 1);
    double max = sqrt(bitset_size(set));
    while(i < max){
        bitset_index_t n = 2 * i;
        while(n <= bitset_size(set)){
            bitset_setbit(set, n, 1);
            n += i;
        }
        i++;
        while(bitset_getbit(set, i)) i++;
    }
}