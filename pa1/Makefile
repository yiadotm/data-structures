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
all: Lex ListClient ListTest
Lex : Lex.o List.o
	gcc -std=c17 -Wall -o Lex Lex.o List.o

Lex.o : Lex.c List.h
	gcc -std=c17 -Wall -c Lex.c

ListClient: ListClient.o List.o
	gcc -std=c17 -Wall -o ListClient ListClient.o List.o

ListClient.o : ListClient.c List.h
	gcc -std=c17 -Wall -c ListClient.c

List.o : List.c List.h
	gcc -std=c17 -Wall -c List.c

ModelListTest: ModelListTest.o List.o
	gcc -std=c17 -Wall -o ModelListTest ModelListTest.o List.o

ModelListTest.o: ModelListTest.c List.h
	gcc -std=c17 -Wall -c ModelListTest.c

ListTest: ListTest.o List.o
	gcc -std=c17 -Wall -o ListTest ListTest.o List.o

ListTest.o: ListTest.c List.h
	gcc -std=c17 -Wall -c ListTest.c

Test: test.o List.o
	gcc -std=c17 -Wall -o test test.o List.o

Test.o: test.c List.h
	gcc -std=c17 -Wall -c test.c

File: file.o List.o
	gcc -std=c17 -Wall -o file file.o List.o

File.o: file.c List.h
	gcc -std=c17 -Wall -c file.c

clean :
	rm -f Lex ListClient Lex.o ListClient.o List.o ListTest ListTest.o

checkClient : 
	valgrind --leak-check=full ListClient

checkLex :
	valgrind --leak-check=full ./Lex input.txt blah3
