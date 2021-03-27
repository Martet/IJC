// steg-decode.c
// Řešení IJC-DU1, příklad b), 23.3.2021
// Autor: Martin Zmitko, xzmitk01
// Přeloženo: gcc 9.3

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "error.h"
#include "ppm.h"
#include "bitset.h"
#include "eratosthenes.h"

#define START_PRIME 23

int main(int argc, char* argv[]){
    //Kontrola argumentu
    if(argc != 2) 
        error_msg("Program musi mit prave 1 argument (jmeno souboru)\n");

    //Otevření souboru, kontrola formátu
    struct ppm *in_ppm = ppm_read(argv[1]);
    if(in_ppm == NULL) 
        return EXIT_FAILURE;

    //Vytvoření bitového pole a jeho vyplnění prvočísly
    bitset_alloc(primes, ppm_size(in_ppm));
    eratosthenes(primes);

    //Zjištění maximální délky zakódované zprávy pro otevřený soubor
    unsigned max_len = 0;
    for(unsigned i = START_PRIME; i < ppm_size(in_ppm); i++){
        if(bitset_getbit(primes, i) == 0)
            max_len++;
    }

    //Alokace paměti pro výslednou zprávu
    char *message = malloc(max_len);
    if(message == NULL){
        ppm_free(in_ppm);
        bitset_free(primes);
        error_msg("Alokace pameti pro vyslednou zpravu selhala\n");
    }

    //Projde data vstupního souboru na pozicích prvočísel
    unsigned len = 0;
    char pos = 0, chr = 0;
    for(unsigned i = START_PRIME; i < ppm_size(in_ppm);){
        //Zaplněný dočasný znak zprávy, uložíme, pokračovat na další
        if(pos > 7){
            message[len] = chr;
            chr = 0;
            if(message[len] == '\0')
                break;
            len++;
            pos = 0;
        }

        //uložení jednoho bitu do dočasného znaku chr
        char in = in_ppm->data[i] & 1;
        in <<= pos++;
        chr |= in;

        //Posun na další prvočíslo
        i++;
        while(bitset_getbit(primes, i) != 0) i++;
    }

    //Kontrola přesažení hranice délky zprávy, zakončení nulou
    if(len >= max_len || message[len] != '\0'){
        ppm_free(in_ppm);
        free(message);
        bitset_free(primes);
        error_msg("Zakodovana zprava neobsahuje nulovy znak\n");
    }

    printf("%s", message);
    
    ppm_free(in_ppm);
    free(message);
    bitset_free(primes);
    return EXIT_SUCCESS;
}