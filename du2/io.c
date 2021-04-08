// io.c
// Řešení IJC-DU2, 2. úkol, 8.4.2021
// Autor: Martin Zmitko, xzmitk01
// Přeloženo: gcc 9.3

#include <stdio.h>
#include <ctype.h>

int read_word(char *s, int max, FILE *f){
    int next_char = fgetc(f), count = 0;
    //consume all whitespace before word
    while(isspace(next_char))
        next_char = fgetc(f);

    //return if at end of stream
    if(next_char == EOF)
        return 0;

    //loop through non whitespace characters until max and save them
    while(!isspace(next_char) && count < max - 1){
        s[count] = next_char;
        count++;
        next_char = fgetc(f);
    }
    
    //put back last character so nothing after word is read
    ungetc(next_char, f);
    s[count] = 0;
    return count;
}
