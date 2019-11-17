#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <assert.h>



int main(){

    int i = 0;
    for (i; i < 100; i++){
        int choice1 = rand() % 4;
        int currentPlayer = rand() % 4;
        //setting up the test case taken from the example
        struct gameState G, testG;
        int numPlayers = rand() % 3;
        int seed = 1000;
        int z = 0;
        int k[10];
        for (z; z < 10; z++){
            k[z] = rand() % 27;
        }
        
        initializeGame(numPlayers, k, seed, &G);
        memcpy(&testG, &G, sizeof(struct gameState));

        printf("%s", "This is the test for the baron card\n");
        baron_function(currentPlayer, &testG, choice1);
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
    }
    




return 0;


}