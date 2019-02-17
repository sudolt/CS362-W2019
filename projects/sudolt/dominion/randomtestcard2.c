/*******************************************************************************
 *
 * Name:    Tim Sudol
 * Class:   CS362 - Winter 2019
 * Date:    17 FEB 2019
 * Program: randomtestcard2.c
 *
 * This program verifies the function of the council room card in dominion.c.  
 *
 * The strategy is to play the card and compare hand sizes before and after the
 * card was played.  The card increases everybody's hand size by one except for
 * the current player who adds 3, and adds a buy for the player.  This test will
 * compare the hand sizes before and after for each player, as well as the 
 * number of buys.
 *
 * This function has been modified to randomly create a seed to use.
 *
 ******************************************************************************/

// Include the required header files, nothing fancy is needed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dominion.h"
#include "dominion_helpers.h"

#define MAX_TESTS 5000

// Not using assert... exiting the program on an issue is a horrible way of
// trying to debug problems.  This comp function replaces assert.
int comp(int testValue)
{
   // If the comparison that calls comp is true, print out a statement verifying
   // the test passed and return the value 0 so the number of bugs does not get
   // increased.
   if (testValue)
   {
//      printf("Test passed\n\n");
      return 0;
   }
   // Since the comparison failed, print out an error message and then return
   // the value 1 so we can keep count of the number of bugs in the function.
   else
   {
//      printf("Test failed!\n\n");
      return 1;
   }

   return -1;
}

int main()
{
   // Keep track of the number of bugs
   int numBugsSelf = 0;
   int numBugsOthers = 0;
   int numBugsBuy = 0;
   int numBugsTest = 0;
   int goodRunsSelf = MAX_TESTS;
   int goodRunsOthers = MAX_TESTS;
   int goodRunsBuy = MAX_TESTS;
   int goodRunsTest = MAX_TESTS;
   int testNum = 0;

   srand(time(NULL));

   printf("Testing council room card\n");
   for (testNum = 0; testNum < MAX_TESTS; ++testNum)
   {
      // Set up the variables used to call initializeGame
      int numPlayers = 2;
      int kc[10] = {adventurer, council_room, feast, copper, gold,
                     village, cutpurse, embargo, outpost, smithy};

      int randomSeed;
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


      randomSeed = rand();
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

      //printf("Testing if council played correctly:\t");
      numBugsTest += comp(test == 0);

      for (int i = 0; i < numPlayers; ++i)
      {
         numCardsHandAfter[i] = state.handCount[i];
      }

      //printf("Testing the number of cards in each player's hand\n");
      for (int i = 0; i < numPlayers; ++i)
      {
         //printf("Player %d\t Before: %d\t After: %d\t", 
         //         i, numCardsHandBefore[i], numCardsHandAfter[i]);
         if (i == 0)
         {
            numBugsSelf += comp(numCardsHandBefore[i] + 3  == numCardsHandAfter[i]);
            goodRunsSelf -= comp(numCardsHandBefore[i] + 3  == numCardsHandAfter[i]);
         }
         else
         {
            numBugsOthers += comp(numCardsHandBefore[i] + 1 == numCardsHandAfter[i]);
            goodRunsOthers -= comp(numCardsHandBefore[i] + 1 == numCardsHandAfter[i]);
         }
      }

      //printf("Testing number of buys before: %d\t after: %d\t",
      //          numBuysBefore, numBuysAfter);
      numBugsBuy += comp(numBuysBefore + 1 == numBuysAfter);
      goodRunsBuy -= comp(numBuysBefore + 1 == numBuysAfter);
   }

   printf("%d hands had issues with own number of cards\n", numBugsSelf);
   printf("%d hands had no issues with own number of cards\n", goodRunsSelf);
   printf("%d hands had issues with other players number of cards\n", numBugsOthers);
   printf("%d hands had no with other players number of cards\n", goodRunsOthers);
   printf("%d hands had issues with number of buys\n", numBugsBuy);
   printf("%d hands had no issues with number of buys\n", goodRunsBuy);
   printf("%d hands had issues with council_card function\n", numBugsTest);
   printf("%d hands had no issues with council_card function\n", goodRunsTest);
   

   return 0;
}
