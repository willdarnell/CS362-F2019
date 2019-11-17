#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"



int main(){

    int i = 0;
    for (i; i < 100; i++){
        int choice1 = rand() % 4;
        int choice2 = rand() % 4;

        int currentPlayer = rand() % 4;
        //setting up the test case taken from the example
        struct gameState G, testG;
        int numPlayers = rand() % 3;
        int thisPlayer = rand() % 3;
        int handpos = rand() % 3;

        int seed = 1000;
        int z = 0;
        int k[10];
        for (z; z < 10; z++){
            k[z] = rand() % 27;
        }
        
        
        initializeGame(numPlayers, k, seed, &G);
        
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
        //second test to see if the coins is increased by 2 if the first choice is taken, which reveals the first bug
        //that I added for the minion function. This test fails because I changed the conditional to not increment the coins.
        if (testG.coins == (G.coins + 2)){
            printf("%s", "The number of coins was increased correctly.\n");
        }
        else {
            printf("%s", "The number of coins was not increased correctly.\n");

        }
    }
    


return 0;




}