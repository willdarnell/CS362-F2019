#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "mine"

int main () {

//int mine(int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus, int j, int currentPlayer){
int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0, j = 0;
int return_number;
//setting up the test case taken from the example
struct gameState G, testG;
int numPlayers = 2;
int seed = 1000;
int k[10] = {copper, gold, silver, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};
initializeGame(numPlayers, k, seed, &G);
choice2 = 2;
memcpy(&testG, &G, sizeof(struct gameState));
printf("%s""%d", "THIS IS THE OPENING HAND COUNT: ", G.handCount[0]);
printf("%s", "\n");

printf("%s", "This is the test for the mine card\n");
return_number = mine_function(choice1, choice2, choice3, &testG, handpos, bonus, j, 0);
if ((G.hand[0][0] == copper) && (getCost(G.hand[0][0]) + 3 <= getCost(choice2))){
    if (return_number == 0){
        printf("%s", "the function executed when it should\n");
    }
    else{
        printf("%s", "the function failed when it shouldn't\n");
    }

}

//test gainCard on line 706
//need to add in the discarded cards

if (++G.handCount[0] == testG.handCount[0]){
    printf("%s""%d", "Player gained a card as they were meant to.", G.handCount[0]);
}
else {
    printf("%s""%d", "Player did not gain the card like they were meant to.\n", testG.handCount[0]);
}




return 0;

}