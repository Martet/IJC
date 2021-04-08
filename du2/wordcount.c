#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "htab.h"
#include "htab_private.h"

int main(){
    htab_t *htab = htab_init(10);
    htab_pair_t *pair = htab_lookup_add(htab, "bruh");
    pair = htab_lookup_add(htab, "bruh");
    pair->value++;
    htab_lookup_add(htab, "n3");
    pair = htab_lookup_add(htab, "bruh0");
    printf("%d\n", pair->value);
    pair = htab_lookup_add(htab, "bruh");
    printf("%d\n", pair->value);

    htab_erase(htab, "n");
    htab_t *h = htab_move(5, htab);


    htab_free(htab);
    htab_free(h);
    return 0; 
}
