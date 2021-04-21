// htab_hash_function.c
// Řešení IJC-DU2, 2. úkol, 8.4.2021
// Autor: Martin Zmitko, xzmitk01
// Přeloženo: gcc 9.3

#include <string.h>
#include <stdint.h>

//returns hash of key
size_t htab_hash_function(const char *str) {
    uint32_t h = 0; 
    #ifdef HASHTEST //another hash implementation (much worse)
        unsigned i = 0;
        while(str[i] != 0){
            h += str[i] * 4096;
        }
    #else
        const unsigned char *p;
        for(p = (const unsigned char*)str; *p != '\0'; p++)
            h = 65599 * h + *p;
    #endif
    return h;
}
