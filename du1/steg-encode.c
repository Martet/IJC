// steg-encode.c
// Řešení IJC-DU1, příklad b) bonusový, 23.3.2021
// Autor: Martin Zmitko, xzmitk01
// Přeloženo: gcc 9.3
// Poznámka: Program se spouští ve formátu "./steg-encode zdroj cíl zpráva"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "error.h"
#include "ppm.h"
#include "bitset.h"
#include "eratosthenes.h"

int main(int argc, char* argv[]){
    //Kontrola argumentů a načtení .ppm obrázku
    if(argc != 4) 
        error_msg("Program musi mit argumenty ve formatu \"steg-encode zdrojovy_obrazek cilovy_obrazek zprava\"\n");
    struct ppm *in_ppm = ppm_read(argv[1]);
    if(in_ppm == NULL) 
        return EXIT_FAILURE;

    //Vytvoření bitového pole prvočísel a nalezení maximální délky zprávy
    bitset_alloc(primes, ppm_size(in_ppm));
    eratosthenes(primes);
    unsigned max_len = 0;
    for(unsigned i = 23; i < ppm_size(in_ppm); i++){
        if(bitset_getbit(primes, i) == 0)
            max_len++;
    }

    //Kontrola délky zprávy, když se nevejde, program se ukončí
    if(max_len < 8 || strlen(argv[3]) + 8 > max_len / 8){
        ppm_free(in_ppm);
        bitset_free(primes);
        error_msg("Zprava o delce %u bytu se nevesla do obrazku s kapacitou %u bytu\n", strlen(argv[3]), max_len / 8 - 8);
    }

    //Zapsání dat do obrázku
    unsigned i = 23, len = 0, n = 0;
    int c;
    while((c = argv[3][n]) != '\0'){
        for(int bit = 0; bit < 8; bit++){
            if(len + 8 >= max_len)
                break;
            char out_bit = ((char)c >> bit) & 1;
            in_ppm->data[i] = (in_ppm->data[i] & ~1) | out_bit;
            do{
                if(++i > ppm_size(in_ppm) - 8) break;
            } while(bitset_getbit(primes, i) != 0);
            len++;
        }
        n++;
    }

    //Zapsání ukončovacího nulového znaku do obrázku
    for(int bit = 0; bit < 8; bit++){
        in_ppm->data[i] = in_ppm->data[i] & ~1;
        do i++;
        while(bitset_getbit(primes, i) != 0);
    }

    ppm_write(argv[2], in_ppm);

    ppm_free(in_ppm);
    bitset_free(primes);
    return EXIT_SUCCESS;
}