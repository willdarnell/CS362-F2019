#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "baron"
//int baron_function(int currentPlayer, struct gameState *state, int choice1)
int main () {

int choice1 = 1;
int currentPlayer = 0;
//setting up the test case taken from the example
struct gameState G, testG;
int numPlayers = 2;
int seed = 1000;
int k[10] = {estate, gold, silver, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};
initializeGame(numPlayers, k, seed, &G);
memcpy(&testG, &G, sizeof(struct gameState));

printf("%s", "This is the test for the baron card\n");
baron_function(currentPlayer, &testG, choice1);

//test for number of buys increasing by one

if (testG.numBuys == ++G.numBuys){
    printf("%s", "the number of buys was incremented correctly.\n");
}
else {
     printf("%s", "the number of buys was NOT incremented correctly.\n");
}

//this function finds the first bug that I entered, which was changing the boolean flag to start as false, which 
//made the first branch never execute.
if ((testG.coins == G.coins) && (testG.supplyCount[estate] == G.supplyCount[estate])){
     printf("%s", "the function is not working properly and did not execute.");
}
else {
     printf("%s", "at least one branch of the function ran correctly.");
}

return 0;
}
