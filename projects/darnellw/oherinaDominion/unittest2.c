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
int handPos = 0;
//setting up the test case taken from the example
struct gameState G, testG;
int numPlayers = 2;
int seed = 1000;
int k[10] = {estate, gold, silver, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};
initializeGame(numPlayers, k, seed, &G);
memcpy(&testG, &G, sizeof(struct gameState));

printf("%s", "This is the test for the baron card\n");
cardEffectBaron(choice1, &testG, currentPlayer, handPos);


//test for number of buys increasing by one

if (testG.numBuys == ++G.numBuys){
    printf("%s", "the number of buys was incremented correctly.\n");
}
else {
     printf("%s", "the number of buys was NOT incremented correctly.\n");
}

//this function finds the first bug that I entered, which was changing the boolean flag to start as false, which 
//made the first branch never execute but I am going to change that flag back in the source code so that I can 
//achieve test coverage.
if ((testG.coins == G.coins) && (testG.supplyCount[estate] == G.supplyCount[estate])){
     printf("%s", "the function is not working properly and did not execute.\n");
}
else {
     printf("%s", "at least one branch of the function ran correctly.\n");
}

//check the number of coins math
//this test finds the second bug that I added, changing the coin change from + 4 to -4. 
if (testG.coins == (G.coins + 4)){
    printf("%s", "The function is doing the math correctly since there is one estate card in the players hand.\n");
}
else {
    printf("%s", "the function is not doing the math correctly in terms of coins.\n");

}
choice1 = 0;
//the case for executing the second branch
cardEffectBaron(choice1, &testG, currentPlayer, handPos);


//another test case for if the second player gains the estate card
choice1 = 1;
int j[10] = {curse, gold, silver, minion, mine, cutpurse,
			sea_hag, tribute, estate, council_room};
initializeGame(numPlayers, j, seed, &G);
struct gameState testF;
memcpy(&testF, &G, sizeof(struct gameState));
testF.supplyCount[estate] = 1;

cardEffectBaron(choice1, &testF, currentPlayer, handPos);
G.supplyCount[estate] = 1;

//test to see if the supply count is double decremented when supply is 1. is a bug in the gain card function.
if (testF.supplyCount[estate] == (G.supplyCount[estate] - 2)){
    printf("%s", "The estate card was successfully removed from the supply.\n");
    printf("%d", testF.supplyCount[estate]);
    printf("%d", G.supplyCount[estate]);



}
else {
    printf("%s", "the estate card was not successfully removed from the supply.\n");
    printf("%d", testF.supplyCount[estate]);
    printf("%d", G.supplyCount[estate]);
}
return 0;
}
