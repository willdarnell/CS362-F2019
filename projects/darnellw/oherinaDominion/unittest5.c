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
struct gameState G, testG, testk;
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
initializeGame(numPlayers, k, seed, &G);
memcpy(&testk, &G, sizeof(struct gameState));
testk.deck[1][5] = smithy;
testk.deck[1][6] = mine;
testk.deck[1][7] = mine;
testk.deck[1][8] = smithy;
tribute_function(currentPlayer, nextPlayer, tributeRevealedCards, &testk);
//second test checks to see if the second revealed card equals smithy like it is supposed to. this finds
//the second assignment bug which is setting it to copper instead of checking for copper.
if (tributeRevealedCards[1] == 13){
    printf("%s", "The tribute funciton is working correctly.\n");
}
else {
    printf("%s""%d", "The tribute function is not correctly assigning tribute revealed cards.\n"), tributeRevealedCards[1];

}

//this test initializes the deckcount of the nextplayer with only one card.
initializeGame(numPlayers, k, seed, &G);
memcpy(&testk, &G, sizeof(struct gameState));
testk.discardCount[1]=0;
testk.deckCount[1] = 1;
tribute_function(currentPlayer, nextPlayer, tributeRevealedCards, &testk);

if (testk.deckCount[1] == 0){
        printf("%s", "The tribute funciton is working correctly for a one card deck.\n");

}
else {
            printf("%s", "The tribute funciton is  not working correctly.\n");

}

//this test reverses the previous test and checks the discard pile
initializeGame(numPlayers, k, seed, &G);
memcpy(&testk, &G, sizeof(struct gameState));
testk.discardCount[1]=1;
testk.deckCount[1] = 0;
tribute_function(currentPlayer, nextPlayer, tributeRevealedCards, &testk);

if (testk.discardCount[1] == 0){
        printf("%s", "The tribute funciton is working correctly for a no card deck.\n");

}
else {
            printf("%s", "The tribute funciton is  not working correctly.\n");

}

//this test reverses the previous test and checks the discard pile
initializeGame(numPlayers, k, seed, &G);
memcpy(&testk, &G, sizeof(struct gameState));
testk.discardCount[1]=10;
testk.deckCount[1] = 0;
tribute_function(currentPlayer, nextPlayer, tributeRevealedCards, &testk);

if (testk.discardCount[1] == 5){
        printf("%s", "The tribute funciton is working correctly for a no card deck with a large discard pile.\n");

}
else {
            printf("%s""%d", "The tribute funciton is not working correctly.\n", testk.discardCount[1]);

}

return 0;
}