# Makefile
# Řešení IJC-DU2, 20.4.2021
# Autor: Martin Zmitko, xzmitk01
# Přeloženo: gcc 9.3

CFLAGS = -g -std=c99 -pedantic -Wall -Wextra -O2
LDFLAGS_ = -lm
CC = gcc

all: tail libhtab.a wordcount

wordcountcc: wordcount.cc
	g++ -std=c++11 -O2 wordcount.cc -o wordcount

wordcount: wordcount.o libhtab.a
	$(CC) $(CFLAGS) $<  -L. -lhtab -o $@

libhtab.a: htab_init.o htab_hash_function.o htab_size.o htab_bucket_count.o
	ar rcs $@ $^


#htab%.o: htab*.c htab*.h
#	$(CC) $(CFLAGS) -fPIC -c $< -o $@

zip:
	rm -f xzmitk01.zip
	zip xzmitk01.zip *.c *.h Makefile

clean:
	rm -f *.o tail wordcount xzmitk01.zip

.PHONY: clean zip all run
