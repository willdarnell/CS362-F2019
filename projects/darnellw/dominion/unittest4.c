#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>


//this is the unit test for the ambassador function
int main () {
//int ambassador_function(int choice1, int choice2, int j, int handPos, struct gameState *state, int currentPlayer){

int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0, j = 0;

int currentPlayer = 0;
//setting up the test case taken from the example
struct gameState G, testG;
int numPlayers = 2;
int seed = 1000;
int k[10] = {ambassador, gold, silver, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};
initializeGame(numPlayers, k, seed, &G);
memcpy(&testG, &G, sizeof(struct gameState));
testG.hand[0][1] = smithy;
testG.hand[0][2] = smithy;
testG.hand[0][3] = smithy;
testG.hand[0][4] = smithy;

choice1 = 1;
choice2 = 2;
int before_call = (testG.supplyCount[testG.hand[currentPlayer][choice1]]) += choice2;
ambassador_function(choice1, choice2, j, handpos, &testG, currentPlayer);
printf("%s""%d", "THIS IS THE SUPPLY BEFORE THE CALL and BEFORE ADDING TWO: ", testG.supplyCount[testG.hand[currentPlayer][choice1]]);
printf("%s", "\n");

//the first test will check to see if the supply of the revealed card is increased by 2, but will also find the first
//bug which will cause the program to exit with any choice for choice2, so that is now commented out.
if ((testG.supplyCount[testG.hand[currentPlayer][choice1]]) == (before_call)){
	printf("%s""%d", "The correct number of choice1 cards were added to the supply.", before_call);
	printf("%s", "\n");
	printf("%d", testG.supplyCount[testG.hand[currentPlayer][choice1]]);
}
else {
		printf("%s", "The incorrect number of choice1 cards were added to the supply.\n");

}

//the same test with only one card chosen to discard successfully increases the supply by choice2 and then 
//decrements it for each other player, making it net zero.
memcpy(&testG, &G, sizeof(struct gameState));
choice2 = 1;
before_call = (testG.supplyCount[testG.hand[currentPlayer][choice1]]) += choice2;
ambassador_function(choice1, choice2, j, handpos, &testG, currentPlayer);
printf("%s""%d", "THIS IS THE SUPPLY BEFORE THE CALL and BEFORE ADDING TWO: ", testG.supplyCount[testG.hand[currentPlayer][choice1]]);
	printf("%s", "\n");

if (testG.supplyCount[testG.hand[currentPlayer][choice1]] == (before_call)){
	printf("%s""%d", "The correct number of choice1 cards were added to the supply.", before_call);
	printf("%s", "\n");
	printf("%d", testG.supplyCount[testG.hand[currentPlayer][choice1]]);
		printf("%s", "\n");

}
else {
	printf("%s""%d", "The incorrect number of choice1 cards were added to the supply.", before_call);
	printf("%s", "\n");
	printf("%d", testG.supplyCount[testG.hand[currentPlayer][choice1]]);

}

return 0;
}
