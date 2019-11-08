CFLAGS= -Wall -fpic -coverage -lm -std=c99

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/

testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

cardtest1:	
	gcc -fprofile-arcs -ftest-coverage -o cardtest1 -g unittest1.c dominion.c rngs.c 

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

unittestresults: 
	gcc -fprofile-arcs -ftest-coverage -o testcard1 -g unittest1.c dominion.c rngs.c 
	./testcard1 &> unittestresult.out
	gcov -f -b dominion.c >> unittestresult.out
	gcc -fprofile-arcs -ftest-coverage -o testcard2 -g unittest2.c dominion.c rngs.c 
	./testcard2 >> unittestresult.out
	gcov -f -b dominion.c >> unittestresult.out
	gcc -fprofile-arcs -ftest-coverage -o testcard3 -g unittest3.c dominion.c rngs.c 
	./testcard3 >> unittestresult.out
	gcov -f -b dominion.c >> unittestresult.out
	gcc -fprofile-arcs -ftest-coverage -o testcard4 -g unittest4.c dominion.c rngs.c 
	./testcard4 >> unittestresult.out
	gcov -f -b dominion.c >> unittestresult.out
	gcc -fprofile-arcs -ftest-coverage -o testcard5 -g unittest5.c dominion.c rngs.c 
	./testcard5 >> unittestresult.out
	gcov -f -b dominion.c >> unittestresult.out
	
	


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player 

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
