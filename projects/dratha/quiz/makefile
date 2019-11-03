CFLAGS = -Wall -fpic -coverage -lm -std=c99

default: testme

testme:	
	-gcc -o testme -g testme.c $(CFLAGS)
	-testme >> testmeresults.out
	-gcov testme.c -b -f >> testmeresults.out
clean:
	-rm -f testme *.out *gcov *.gcno *gcda
