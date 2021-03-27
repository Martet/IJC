# Makefile
# Řešení IJC-DU2, 20.4.2021
# Autor: Martin Zmitko, xzmitk01
# Přeloženo: gcc 9.3

CFLAGS = -g -std=c11 -pedantic -Wall -Wextra -O2
LDFLAGS_ = -lm
CC = gcc

all: tail wordcount

wordcount: wordcount.cc
	g++ -std=c++11 -O2 wordcount.cc -o wordcount

zip:
	rm -f xzmitk01.zip
	zip xzmitk01.zip *.c *.h Makefile

clean:
	rm -f *.o tail wordcount xzmitk01.zip

.PHONY: clean zip all run