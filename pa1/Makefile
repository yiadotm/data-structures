#------------------------------------------------------------------------------
# Danee Dang, dudang
# 2023 Spring CSE1010 PA1
# Makefile
# Makefile for PA1
# make                   makes Lex
# make ListClient        makes ListClient
# make clean             removes all binaries
# make checkClient       checks ListClient for memory errors
# make checkLex          checks Lex for memory errors
#-----------------------------------------------------------------------------
SHELL := /bin/sh
CC = clang
CFLAGS = -Wall -Werror -Wextra -Wpedantic 
LFLAGS = -lm

all: Lex List ListClient ListTest format

Lex : Lex.o List.o
	$(CC) -o $@ $^ $(LFLAGS)

ListClient: ListClient.o List.o
	$(CC) -o $@ $^ $(LFLAGS)

ListTest: ListTest.o List.o
	$(CC) -o $@ $^ $(LFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f keygen encrypt decrypt *.o

cleankeys:
	rm -f *.{pub,priv}

format:
	clang-format -i -style=file *.[ch]
