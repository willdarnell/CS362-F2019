#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int main (){
//int minion_function(int choice1, int choice2, int j, struct gameState *state, int handPos, int currentPlayer){
int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0, j = 0;
struct gameState G, testG;
int numPlayers = 2;
int seed = 1000;
int k[10] = {copper, gold, silver, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};
initializeGame(numPlayers, k, seed, &G);
choice2 = 2;
memcpy(&testG, &G, sizeof(struct gameState));

printf("%s", "This is the test for the minion card.\n");

//first test to see if the actions are correctly implemented
minion_function(choice1, choice2, 0, &testG, handpos, 0);
if (testG.numActions == ++G.numActions){
    printf("%s", "The number of actions was incremented correctly.\n");
}
else {
    printf("%s", "The number of actions was not incremented correctly.\n");

}







//change the decision to take the coins
choice1 = 1;
minion_function(choice1, choice2, 0, &testG, handpos, 0);
//second test to see if the coins is increased by 2 if the first choice is taken
if (testG.coins == (G.coins + 2)){
    printf("%s", "The number of coins was increased correctly.\n");
}
else {
    printf("%s", "The number of coins was not increased correctly.\n");

}

return 0;
}