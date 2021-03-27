# Makefile
# Řešení IJC-DU1, příklad a), 23.3.2021
# Autor: Martin Zmitko, xzmitk01
# Přeloženo: gcc 9.3

CFLAGS = -g -std=c11 -pedantic -Wall -Wextra -O0
LDFLAGS_ = -lm
CC = gcc

all: primes primes-i steg-decode

run: all
	./primes
	./primes-i

steg-decode: steg-decode.o ppm.o error.o bitset.o eratosthenes.o
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS_)

steg-encode: steg-encode.o ppm.o error.o bitset.o eratosthenes.o
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS_)

primes-i: primes-i.o error.o eratosthenes-i.o bitset-i.o
	$(CC) $(CFLAGS) -DUSE_INLINE $^ -o $@ $(LDFLAGS_)

primes: primes.o error.o eratosthenes.o bitset.o
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS_)

primes-i.o: primes.c
	$(CC) $(CFLAGS) -DUSE_INLINE -c $< -o $@

eratosthenes-i.o: eratosthenes.c eratosthenes.h
	$(CC) $(CFLAGS) -DUSE_INLINE -c $< -o $@

bitset-i.o: bitset.c bitset.h
	$(CC) $(CFLAGS) -DUSE_INLINE -c $< -o $@

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $<

zip:
	rm -f xzmitk01.zip
	zip xzmitk01.zip *.c *.h Makefile

clean:
	rm -f *.o primes primes-i steg-decode steg-encode xzmitk01.zip

.PHONY: clean zip all run
