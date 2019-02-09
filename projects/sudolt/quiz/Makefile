# Tim Sudol
# 09 FEB 2019
# CS362 - Winter 2019
#
# This is the Makefile for the random testing quiz.

CC = gcc
CFLAGS = -Wall -g -fpic -coverage -lm

testme: testme.c
	$(CC) $(CFLAGS) -o testme testme.c

all: testme

default: testme

run: testme
	./testme; echo -e "\n Error in testme.  Code is: $$?"

clean:
	rm -f *.o testme *.gcno *.gcda *.gcov 

