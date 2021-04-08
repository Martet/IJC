// io.h
// Řešení IJC-DU2, 2. úkol, 8.4.2021
// Autor: Martin Zmitko, xzmitk01
// Přeloženo: gcc 9.3

#include <stdio.h>

//reads one word delimited by isspace characters up to max characters into s from stream f
int read_word(char *s, int max, FILE *f);
