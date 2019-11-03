CFLAGS = -Wall -fpic -coverage -lm -std=c99

default: testme

testme: testme.c
	
	-gcc -o testme -g testme.c $(CFLAGS)
	-testme >> testme.out
	-gcov testme.c -b -f >> testme.out
	

clean:
	-rm -f testme *.out *gcov *.gcno *gcda
