/*******************************************************************************
 *
 * Name:    Tim Sudol
 * Class:   CS362 - Winter 2019
 * Date:    27 JAN 2019
 * Program: cardtest3.c
 *
 * This program verifies the function of the council room card in dominion.c.  
 *
 * The strategy is to play the card and compare hand sizes before and after the
 * card was played.  The card increases everybody's hand size by one except for
 * the current player who adds 3, and adds a buy for the player.  This test will
 * compare the hand sizes before and after for each player, as well as the 
 * number of buys.
 *
 ******************************************************************************/

// Include the required header files, nothing fancy is needed
#include <stdio.h>
#include "dominion.h"
#include "dominion_helpers.h"

// Not using assert... exiting the program on an issue is a horrible way of
// trying to debug problems.  This comp function replaces assert.
int comp(int testValue)
{
   // If the comparison that calls comp is true, print out a statement verifying
   // the test passed and return the value 0 so the number of bugs does not get
   // increased.
   if (testValue)
   {
      printf("Test passed\n\n");
      return 0;
   }
   // Since the comparison failed, print out an error message and then return
   // the value 1 so we can keep count of the number of bugs in the function.
   else
   {
      printf("Test failed!\n\n");
      return 1;
   }

   return -1;
}

int main()
{
   // Keep track of the number of bugs
   int numBugs = 0;

   // Set up the variables used to call initializeGame
   int numPlayers = 2;
   int kc[10] = {adventurer, council_room, feast, copper, gold,
                  village, cutpurse, embargo, outpost, smithy};

   int randomSeed = 5;
   struct gameState state;

   // Set up the variables used to call cardEffect
   int card = council_room;
   int choice1 = 0;
   int choice2 = 0;
   int choice3 = 0;
   int handPos = 0;
   int bonus = 0;

   // Testing variables
   int test = 0;     // See if cardEffect worked
   int numCardsHandBefore[4];
   int numCardsHandAfter[4];
   int numBuysBefore = 0;
   int numBuysAfter = 0;

   for (int i = 0; i < numPlayers; ++i)
   {
      numCardsHandBefore[i] = 0;
      numCardsHandAfter[i] = 0;
   }

   printf("Testing council room card\n");

   // Inititalize the game to get everything set up
   initializeGame(numPlayers, kc, randomSeed, &state);

   
   for (int i = 0; i < numPlayers; ++i)
   {
      numCardsHandBefore[i] = state.handCount[i];
   }

   numBuysBefore = state.numBuys;

   // Play the card and see what happens!
   test = cardEffect(card, choice1, choice2, choice3, &state, handPos, &bonus);

   numBuysAfter = state.numBuys;

   printf("Testing if council played correctly:\t");
   numBugs += comp(test == 0);

   for (int i = 0; i < numPlayers; ++i)
   {
      numCardsHandAfter[i] = state.handCount[i];
   }

   printf("Testing the number of cards in each player's hand\n");
   for (int i = 0; i < numPlayers; ++i)
   {
      printf("Player %d\t Before: %d\t After: %d\t", 
               i, numCardsHandBefore[i], numCardsHandAfter[i]);
      if (i == 0)
      {
         numBugs += comp(numCardsHandBefore[i] + 3  == numCardsHandAfter[i]);
      }
      else
      {
         numBugs += comp(numCardsHandBefore[i] + 1 == numCardsHandAfter[i]);
      }
   }

   printf("Testing number of buys before: %d\t after: %d\t",
             numBuysBefore, numBuysAfter);
   numBugs += comp(numBuysBefore + 1 == numBuysAfter);

   if (numBugs == 0)
   {
      printf("No bugs were found in council room card!\n");
   }
   else
   {
      printf("Found %d bugs in council room card!\n", numBugs);
   }

   return 0;
}
