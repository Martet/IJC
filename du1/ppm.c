// ppm.c
// Řešení IJC-DU1, příklad b), 23.3.2021
// Autor: Martin Zmitko, xzmitk01
// Přeloženo: gcc 9.3

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ppm.h"
#include "error.h"

struct ppm * ppm_read(const char * filename){
    //Otevřít soubor
    FILE *file = fopen(filename, "r");
    if(file == NULL){
        warning_msg("Chyba nacteni vstupního souboru\n");
        return NULL;
    }
    
    //Parsování metadat
    char buff[8];
    unsigned xsize, ysize, color;
    int error = fscanf(file, "%s %u %u %u", buff, &xsize, &ysize, &color);
    if(strcmp(buff, "P6") || error != 4 || color != 255 || fgetc(file) != '\n'){
        fclose(file);
        warning_msg("Spatny vstupni format\n");
        return NULL;
    }

    struct ppm *out = calloc(sizeof(unsigned) * 2 + 3 * xsize * ysize, 1);
    if(out == NULL){
        fclose(file);
        warning_msg("Alokace pameti se nezdarila\n");
        return NULL;
    }

    out->xsize = xsize;
    out->ysize = ysize;
    
    //Čtení binárních dat
    int in;
    unsigned i = 0;
    while((in = fgetc(file)) != EOF && i < 3 * xsize * ysize){
        out->data[i] = in;
        i++;
    }

    int next = fgetc(file);
    if((next == '\n' && fgetc(file) != EOF) || next != EOF || i < 3 * xsize * ysize){
        free(out);
        fclose(file);
        warning_msg("Velikost vstupnich dat je %s nez ocekavana velikost\n", 
        i < 3 * xsize * ysize ? "mensi" : "vetsi");
        return NULL;
    }

    fclose(file);
    return out;
}

void ppm_free(struct ppm *p){
    free(p);
}

int ppm_write(const char * filename, struct ppm *p){
    FILE *file = fopen(filename, "w");
    if(file == NULL){
        warning_msg("Chyba nacteni vystupniho souboru\n");
        return EXIT_FAILURE;
    }

    fprintf(file, "P6\n%u %u\n255\n", p->xsize, p->ysize);

    for(unsigned i = 0; i < ppm_size(p); i++){
        fputc(p->data[i], file);
    }

    fclose(file);
    return EXIT_SUCCESS;
}

unsigned ppm_size(struct ppm *p){
    return p->xsize * p->ysize * 3;
}