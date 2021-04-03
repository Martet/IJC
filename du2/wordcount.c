#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "htab.h"

int main(){
    htab_t *htab = htab_init(10);
    htab_pair_t *pair = htab_lookup_add(htab, "bruh");
    pair->value = 3;
    pair = htab_lookup_add(htab, "bruh");
    printf("%d\n", pair->value);
    return 0; 
}
