// bitset.h
// Řešení IJC-DU1, příklad a), 23.3.2021
// Autor: Martin Zmitko, xzmitk01
// Přeloženo: gcc 9.3

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "error.h" 

//Typ bitového pole (pro předávání parametru do funkce odkazem)
typedef unsigned long *bitset_t;

//Typ indexu do bitového pole
typedef unsigned long bitset_index_t;

//Velikost unsigned long v bitech
#define ULONG_SIZE (sizeof(unsigned long) * 8)

//definuje a nuluje proměnnou name
#define bitset_create(name, size) unsigned long name[(size) / ULONG_SIZE + ((size) % ULONG_SIZE == 0 ? 1 : 2)] = {0}; \
    static_assert(size > 0, "Pole musí mít velikost větší než nula\n"); \
    name[0] = size

//definuje proměnnou name a dynamicky ji alokuje
#define bitset_alloc(name, size) \
    assert(size > 0); \
    bitset_t name = calloc((size) / ULONG_SIZE + ((size) % ULONG_SIZE == 0 ? 1 : 2), sizeof(unsigned long)); \
    if(name == NULL) error_msg("bitset_alloc: Chyba alokace paměti\n"); \
    name[0] = size

#ifndef USE_INLINE

//uvolní paměť dynamicky (bitset_alloc) alokovaného pole
#define bitset_free(name) free(name)

//vrátí deklarovanou velikost pole v bitech (uloženou v poli)
#define bitset_size(name) name[0]

//nastaví zadaný bit v poli na hodnotu zadanou výrazem
#define bitset_setbit(name, index, value) \
    if(index > name[0]) error_msg("bitset_setbit: Index %lu mimo rozsah 0..%lu\n", \
               (unsigned long)index, (unsigned long)name[0]); \
    if(value){ \
        name[1 + (index) / ULONG_SIZE] |= (1UL << (ULONG_SIZE - 1)) >> ((index) % ULONG_SIZE); \
    } else { \
        name[1 + (index) / ULONG_SIZE] &= ~((1UL << (ULONG_SIZE - 1)) >> ((index) % ULONG_SIZE)); \
    }

//získá hodnotu zadaného bitu, vrací hodnotu 0 nebo 1
#define bitset_getbit(name, index) (index <= name[0] ? \
    ((name[1 + (index) / ULONG_SIZE] >>  ((index) % ULONG_SIZE == 0 ? \
    ULONG_SIZE - 1 : ( -((index) % ULONG_SIZE - ULONG_SIZE) - 1 )   )) % 2) : \
    (error_msg("bitset_getbit: Index %lu mimo rozsah 0..%lu\n", \
               (unsigned long)index, (unsigned long)name[0]), (int)0))

#else

inline void bitset_free(bitset_t name){
    free(name);
}

inline bitset_index_t bitset_size(bitset_t name){
    return name[0];
}

inline void bitset_setbit(bitset_t name, bitset_index_t index, int value){
    if(index > name[0]) 
        error_msg("bitset_setbit: Index %lu mimo rozsah 0..%lu\n", (unsigned long)index, (unsigned long)name[0]);
    if(value){ 
        name[1 + index / ULONG_SIZE] |= (1UL << (sizeof(unsigned long) * 8 - 1)) >> (index % ULONG_SIZE); 
    } else { 
        name[1 + index / ULONG_SIZE] &= ~((1UL << (sizeof(unsigned long) * 8 - 1)) >> (index % ULONG_SIZE)); 
    }
}

inline int bitset_getbit(bitset_t name, bitset_index_t index){
    if(index > name[0]) 
        error_msg("bitset_getbit: Index %lu mimo rozsah 0..%lu\n", (unsigned long)index, (unsigned long)name[0]);
    return (name[1 + index / ULONG_SIZE] >>  (index % ULONG_SIZE == 0 ?
     ULONG_SIZE - 1 : ( -(index % ULONG_SIZE - ULONG_SIZE) - 1 )   )) % 2;
}

#endif