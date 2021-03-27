// primes.c
// Řešení IJC-DU1, příklad a), 23.3.2021
// Autor: Martin Zmitko, xzmitk01
// Přeloženo: gcc 9.3

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "error.h"
#include "eratosthenes.h"

int main(){
    //Začátek měření času
    clock_t start = clock();

    bitset_create(set, 200000000);
    eratosthenes(set);

    bitset_index_t count = 9;
    bitset_index_t i = bitset_size(set) - 1;
    bitset_index_t primes[10];

    //Uloží 10 největších prvočísel od největších
    while(count < 10){
        if(bitset_getbit(set, i) == 0){
            primes[count] = i;
            count--;
        }
        i--;
    }

    //Vypíše prvočísla od nejmenších
    for(int i = 0; i < 10; i++){
        printf("%lu\n", primes[i]);
    }

    //Konec a výpis měření času
    fprintf(stderr, "Time=%.3g\n", (double)(clock()-start)/CLOCKS_PER_SEC);

    return EXIT_SUCCESS;
}
