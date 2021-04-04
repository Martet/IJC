#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "htab.h"
#include "htab_private.h"

int main(){
    htab_t *htab = htab_init(10);
    htab_pair_t *pair = htab_lookup_add(htab, "bruh");
    pair = htab_lookup_add(htab, "bruh");
    htab_lookup_add(htab, "n3");
    htab_lookup_add(htab, "bruh0");

    htab_erase(htab, "n");
    htab_t *h = htab_move(5, htab);
    printf("%d\n", pair->value);

    htab_free(htab);
    return 0; 
}
