#------------------------------------------------------------------------------
# Danee Dang, dudang
# 2023 Spring CSE1010 PA1
# Makefile
# Makefile for PA1
#-----------------------------------------------------------------------------
SHELL := /bin/sh
CC = clang
CFLAGS = -Wall -Wpedantic -Werror -Wextra 
LIBFLAGS = -lm 
EXECBIN  = Lex


SOURCES = $(wildcard *.c)

OBJECTS = $(SOURCES:%.c=%.o)

.PHONY: all clean

all: $(EXECBIN)
$(EXECBIN): $(OBJECTS)
	$(CC) -o $@ $^ $(LIBFLAGS)

clean:
	rm -f $(EXECBIN) $(OBJECTS)

%.o : %.c
	$(CC) $(CFLAGS) -c $<

