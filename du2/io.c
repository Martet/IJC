#include <stdio.h>
#include <ctype.h>

int read_word(char *s, int max, FILE *f){
    int next_char = fgetc(f), count = 0;
    while(isspace(next_char)){
        if(next_char == EOF)
            return 0;
        next_char = fgetc(f);
    }

    while(!isspace(next_char) && count < max - 1){
        s[count] = next_char;
        count++;
        next_char = fgetc(f);
    }
    s[count] = 0;
    return count;
}
