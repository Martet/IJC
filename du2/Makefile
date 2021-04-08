# Makefile
# Řešení IJC-DU2, 20.4.2021
# Autor: Martin Zmitko, xzmitk01
# Přeloženo: gcc 9.3

CFLAGS =-g -std=c99 -pedantic -Wall -Wextra -O2
CC =gcc
LIBFILES =htab_init.o htab_hash_function.o htab_size.o htab_bucket_count.o htab_find.o htab_lookup_add.o htab_move.o htab_erase.o htab_for_each.o htab_clear.o htab_free.o

all: tail libhtab.a wordcount

wordcountcc: wordcount.cc
	g++ -std=c++11 -O2 wordcount.cc -o wordcountcc

wordcount: wordcount.o io.o libhtab.a
	$(CC) $(CFLAGS) wordcount.o io.o  -L. -lhtab -o $@

libhtab.a: $(LIBFILES)
	ar rcs $@ $^


#htab%.o: htab*.c htab*.h
#	$(CC) $(CFLAGS) -fPIC -c $< -o $@

zip:
	rm -f xzmitk01.zip
	zip xzmitk01.zip *.c *.h Makefile

clean:
	rm -f *.o libhtab.a tail wordcount wordcountcc xzmitk01.zip

.PHONY: clean zip all run
