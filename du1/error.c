// error.c
// Řešení IJC-DU1, příklad b), 23.3.2021
// Autor: Martin Zmitko, xzmitk01
// Přeloženo: gcc 9.3

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "error.h"

#ifndef ERROR_C
#define ERROR_C

void warning_msg(const char *fmt, ...){
    va_list vl;
    va_start(vl, fmt);
    fprintf(stderr, "CHYBA: ");
    vfprintf(stderr, fmt, vl);
    va_end(vl);
}

void error_msg(const char *fmt, ...){
    va_list vl;
    va_start(vl, fmt);
    fprintf(stderr, "CHYBA: ");
    vfprintf(stderr, fmt, vl);
    va_end(vl);
    exit(1);
}

#endif 