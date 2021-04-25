# Makefile
# Řešení IJC-DU2, 20.4.2021
# Autor: Martin Zmitko, xzmitk01
# Přeloženo: gcc 9.3

CFLAGS =-g -std=c99 -pedantic -Wall -Wextra -O2
CC =gcc
LIBFILES =htab_init.o htab_hash_function.o htab_size.o htab_bucket_count.o htab_find.o htab_lookup_add.o htab_move.o htab_erase.o htab_for_each.o htab_clear.o htab_free.o
SHLIBFILES =htab_init_sh.o htab_hash_function_sh.o htab_size_sh.o htab_bucket_count_sh.o htab_find_sh.o htab_lookup_add_sh.o htab_move_sh.o htab_erase_sh.o htab_for_each_sh.o htab_clear_sh.o htab_free_sh.o

all: tail libhtab.a libhtab.so wordcount wordcount-dynamic

wordcountcc: wordcount.cc
	g++ -std=c++11 -O2 wordcount.cc -o wordcountcc

wordcount: wordcount.o io.o libhtab.a
	$(CC) $(CFLAGS) wordcount.o io.o -static -L. -l:libhtab.a -o $@

wordcount-dynamic: wordcount.o io.o libhtab.so
	$(CC) $(CFLAGS) wordcount.o io.o -Wl,-R. -L. -l:libhtab.so -o $@

libhtab.a: $(LIBFILES)
	ar rcs $@ $^

libhtab.so: $(SHLIBFILES)
	$(CC) $(CFLAGS) $^ -shared -o $@

%_sh.o: %.c
	$(CC) $(CFLAGS) -fPIC -c $< -o $@

zip:
	zip xzmitk01.zip *.c *.h Makefile

clean:
	rm -f *.o libhtab.a libhtab.so tail wordcount wordcount-dynamic wordcountcc 

.PHONY: clean zip all run
