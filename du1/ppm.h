// ppm.h
// Řešení IJC-DU1, příklad b), 23.3.2021
// Autor: Martin Zmitko, xzmitk01
// Přeloženo: gcc 9.3

//Struktura pro uložení dat o formátu PPM P6
struct ppm {
    unsigned xsize;
    unsigned ysize;
    char data[];    // RGB bajty, celkem 3*xsize*ysize
};

//Přečte a uloží data ppm ze souboru
struct ppm * ppm_read(const char * filename);

//Uvolní data struktury ppm
void ppm_free(struct ppm *p);

//Zapíše ppm data do souboru
int ppm_write(const char * filename, struct ppm *p);

//Vrátí velikost ppm dat v bytech
unsigned ppm_size(struct ppm *p);