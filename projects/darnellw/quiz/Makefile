CFLAGS = -Wall -fpic -coverage -lm -std=c99

testme: 
	gcc -fprofile-arcs -ftest-coverage -o testme testme.c
clean:
	-rm -f testme *.out *gcov *.gcno *gcda

