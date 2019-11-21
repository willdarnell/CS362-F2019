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
struct gameState G, testG, testK, H;
int numPlayers = 2;
int thisPlayer = 1;
int seed = 1000;
int k[10] = {copper, gold, silver, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};
initializeGame(numPlayers, k, seed, &G);
choice2 = 2;
memcpy(&testG, &G, sizeof(struct gameState));

printf("%s", "This is the test for the minion card.\n");

//first test to see if the actions are correctly implemented
cardEffectMinion(choice1, choice2, 0, &testG, handpos, 0);

if (testG.numActions == ++G.numActions){
    printf("%s", "The number of actions was incremented correctly.\n");
}
else {
    printf("%s", "The number of actions was not incremented correctly.\n");

}


//change the decision to take the coins
choice1 = 1;
cardEffectMinion(choice1, choice2, 0, &testG, handpos, 0);
//second test to see if the coins is increased by 2 if the first choice is taken, which reveals the first bug
//that I added for the minion function. This test fails because I changed the conditional to not increment the coins.
if (testG.coins == (G.coins + 2)){
    printf("%s", "The number of coins was increased correctly.\n");
}
else {
    printf("%s", "The number of coins was not increased correctly.\n");

}

//test case to get into the second half, forgoing the coins.
//first test to check if the player whose turn it is discards hand and draws four cards
initializeGame(numPlayers, k, seed, &H);
choice2 = 2;
H.hand[1][0] = copper;
H.hand[1][1] = copper;
H.hand[1][2] = copper;
H.hand[1][3] = copper;
H.hand[1][4] = copper;
H.hand[1][5] = copper;
H.hand[1][6] = copper;
H.hand[1][7] = copper;
memcpy(&testK, &H, sizeof(struct gameState));
choice1 = 0;
choice2 = 1;
//this test checks to see if the current player discards his entire hand and then gains exactly four cards
//this test finds the other bug that I inserted into this program.
printf("%s""%d", "Current player's handcount before the function is called.", testK.handCount[0]);
printf("%s", "\n");
int pre_call_hand_count = testK.handCount[0];
testK.hand[1][0] = copper;
testK.hand[1][1] = copper;
testK.hand[1][2] = copper;
testK.hand[1][3] = copper;
testK.hand[1][4] = copper;
testK.hand[1][5] = copper;
testK.hand[1][6] = copper;
testK.hand[1][7] = copper;
//testK.handCount[1] = 8;

printf("%s""%d", "Other player's handcount before the function is called.", testK.handCount[1]);
printf("%s", "\n");
int pre_call_hand_count1 = testK.handCount[1];
cardEffectMinion(choice1, choice2, 0, &testG, 1, 0);
printf("%s""%d", "Current player's handcount at the end of the round.", testK.handCount[0]);
printf("%s", "\n");
if ((testK.handCount[0] == (pre_call_hand_count - pre_call_hand_count + 4))){
    printf("%s", "The function for the current player is correctly discarding the hand and drawing exactly four cards.\n");

}
else {
    printf("%s", "The function is not working correctly. The player does not have the correct number of cards.\n");
}


//this second part of the test checks to see if the other players in the round discard their
//entire hands and then gain exactly four cards.
printf("%s""%d", "Other player's handcount at the end of the round.", testK.handCount[1]);
printf("%s", "\n");
if ((testK.handCount[1] == (pre_call_hand_count1 - pre_call_hand_count1 + 4))){
    printf("%s", "The function for the other player is correctly discarding the hand and drawing exactly four cards.\n");

}
else {
    printf("%s", "The function is not working correctly. The other player does not have the correct number of cards.\n");
}



return 0;
}