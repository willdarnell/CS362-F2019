#ifndef _DOMINION_HELPERS_H
#define _DOMINION_HELPERS_H

#include "dominion.h"

int drawCard(int player, struct gameState *state);
int updateCoins(int player, struct gameState *state, int bonus);
int discardCard(int handPos, int currentPlayer, struct gameState *state,
                int trashFlag);
int gainCard(int supplyPos, struct gameState *state, int toFlag, int player);
int getCost(int cardNumber);
int cardEffect(int card, int choice1, int choice2, int choice3,
               struct gameState *state, int handPos, int *bonus);
int mine(int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus, int j, int currentPlayer);
int baron(int currentPlayer, struct gameState *state);
int minion(int choice1, int choice2, int j, struct gameState *state, int handPos, int currentPlayer);
int ambassador(int choice1, int choice2, int j, int handPos, struct gameState *state, int currentPlayer);


#endif
