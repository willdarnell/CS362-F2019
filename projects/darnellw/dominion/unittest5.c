#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>


//this is the unit test for the ambassador function
int main () {
//int tribute(int currentPlayer, int nextPlayer, int tributeRevealedCards, struct gameState *state){
printf("%s", "This is the test for the tribute card\n");


int currentPlayer = 0;
int nextPlayer = 1;
int tributeRevealedCards[2];
//setting up the test case taken from the example
struct gameState G, testG;
int numPlayers = 2;
int seed = 1000;
int k[10] = {ambassador, gold, silver, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};
initializeGame(numPlayers, k, seed, &G);
memcpy(&testG, &G, sizeof(struct gameState));
testG.deck[1][5] = smithy;
testG.deck[1][6] = mine;
testG.deck[1][7] = mine;
testG.deck[1][8] = smithy;
tribute_function(currentPlayer, nextPlayer, tributeRevealedCards, &testG);

//first test to find the first bug, which is an assignment bug, finding it requires commenting out a later for loop 
//that has the second bug.
if (tributeRevealedCards[1] == -1){
    printf("%s", "There is a bug in the tribute logic.\n");
}
else {
    printf("%s""%d", "The check to see if the cards are the same that are revealed works.\n"), tributeRevealedCards[0];

}

return 0;
}