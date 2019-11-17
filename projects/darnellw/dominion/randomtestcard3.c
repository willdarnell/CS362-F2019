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
        int currentPlayer = rand() % 3;
        //setting up the test case taken from the example
        struct gameState G, testG;
        int nextPlayer = rand() % 2;
        int numPlayers = rand() % 3;

        int seed = 1000;
        int z = 0;
        int tributeRevealedCards[2];
        int k[10];
        for (z; z < 10; z++){
            k[z] = rand() % 27;
        }
        
        initializeGame(numPlayers, k, seed, &G);
        memcpy(&testG, &G, sizeof(struct gameState));

        printf("%s", "This is the test for the tribute card\n");
        tribute_function(currentPlayer, nextPlayer, tributeRevealedCards, &testG);
        if (tributeRevealedCards[1] == -1){
            printf("%s", "There is a bug in the tribute logic.\n");
        }
        else {
            printf("%s""%d", "The check to see if the cards are the same that are revealed works.\n"), tributeRevealedCards[0];

        }
        if (tributeRevealedCards[1] == 13){
            printf("%s", "The tribute funciton is working correctly.\n");
        }
        else {
            printf("%s""%d", "The tribute function is not correctly assigning tribute revealed cards.\n"), tributeRevealedCards[1];

        }
        if (testG.deckCount[1] == 0){
            printf("%s", "The tribute funciton is working correctly for a one card deck.\n");

        }
        else {
            printf("%s", "The tribute funciton is  not working correctly.\n");

        }

    }
    


return 0;




}