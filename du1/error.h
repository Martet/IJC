// error.h
// Řešení IJC-DU1, příklad b), 23.3.2021
// Autor: Martin Zmitko, xzmitk01
// Přeloženo: gcc 9.3

#ifndef ERROR_H
#define ERROR_H

//Vytiskne chybovou hlášku ve formátu "CHYBA: ..."
void warning_msg(const char *fmt, ...);

//Vytiskne chybovou hlášku ve formátu "CHYBA: ..." a ukončí program s
//chybovým kódem 1
void error_msg(const char *fmt, ...);

#endif