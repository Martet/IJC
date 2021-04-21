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

//total bucket count, unknown data size so it has to be big enough, primes work better
#define HTAB_BCOUNT 100003
#define MAX_LEN 128

//definitions of error messages
#define mallocErr "memory allocation failed"
#define lenErr "word was truncated to the max length of 127 chars"

//Function for printing key/value pairs
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
    //read words until there are some to be read
    while(read_word(buf, MAX_LEN, stdin) > 0){
        //add the word to hashtab and check if added correctly
        htab_pair_t *pair = htab_lookup_add(t, buf);
        if(pair == NULL){
            htab_free(t);
            fprintf(stderr, "ERROR: %s\n", mallocErr);
            return 1;
        }
        pair->value++;

        //if next character isnt whitespace, whole word wasn't read
        int next_char = getc(stdin);
        if(!isspace(next_char)){
            if(!printedErr){ //print error if not printed
                fprintf(stderr, "WARNING: %s\n", lenErr);
                printedErr = true;
            }
            //read and thrash rest of characters in word
            while(!isspace(next_char) && next_char != EOF)
                next_char = getc(stdin);
        }
    }

    #ifdef MOVETEST
    htab_t *new = htab_move(50000, t);
    htab_free(t);
    t = new;
    #endif

    //print words
    htab_for_each(t, &printWord);

    htab_free(t);
    return 0; 
}
