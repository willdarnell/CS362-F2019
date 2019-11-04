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

int choice1 = 0;
int currentPlayer = 0;
//setting up the test case taken from the example
struct gameState G, testG;
int numPlayers = 2;
int seed = 1000;
int k[10] = {copper, gold, silver, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};
initializeGame(numPlayers, k, seed, &G);
memcpy(&testG, &G, sizeof(struct gameState));

printf("%s", "This is the test for the baron card\n");
baron_function(currentPlayer, &testG, choice1);

return 0;
}
