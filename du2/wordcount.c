// wordcount.c
// Řešení IJC-DU2, 2. úkol, 8.4.2021
// Autor: Martin Zmitko, xzmitk01
// Přeloženo: gcc 9.3

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "htab.h"
#include "io.h"

#define HTAB_BCOUNT 100000
#define MAX_LEN 128

//definitions of error messages
#define mallocErr "memory allocation failed"
#define lenErr "word was truncated to the max length of 127 chars"

void printWord(htab_pair_t *pair){
    printf("%s\t%d\n", pair->key, pair->value);
}

int main(){
    htab_t *t = htab_init(HTAB_BCOUNT);
    if(t == NULL){
        fprintf(stderr, "ERROR: %s\n", mallocErr);
        return 1;
    }

    bool printedErr = false;
    char buf[MAX_LEN];
    while(read_word(buf, MAX_LEN, stdin) > 0){
        htab_pair_t *pair = htab_lookup_add(t, buf);
        if(pair == NULL){
            htab_free(t);
            fprintf(stderr, "ERROR: %s\n", mallocErr);
            return 1;
        }
        pair->value++;

        int next_char = getc(stdin);
        if(!isspace(next_char)){
            if(!printedErr){
                fprintf(stderr, "WARNING: %s\n", lenErr);
                printedErr = true;
            }
            while(!isspace(next_char) && next_char != EOF)
                next_char = getc(stdin);
        }
    }

    htab_for_each(t, &printWord);

    htab_free(t);
    return 0; 
}
