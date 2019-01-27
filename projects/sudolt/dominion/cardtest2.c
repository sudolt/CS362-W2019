/*******************************************************************************
 *
 * Name:    Tim Sudol
 * Class:   CS362 - Winter 2019
 * Date:    27 JAN 2019
 * Program: unittest2.c
 *
 * This program verifies the function of the adventure card in dominion.c.  
 *
 * The strategy is to play the card and compare hand sizes before and after the
 * card was played.  The card has you draw cards until two treasure cards are
 * found, resulting in a change in hand size of +2. That will be the test.
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
   int card = adventurer;
   int choice1 = 0;
   int choice2 = 0;
   int choice3 = 0;
   int handPos = 0;
   int bonus = 0;

   // Testing variables
   int test = 0;     // See if cardEffect worked
   int numCardsHandBefore = 0;
   int numCardsHandAfter = 0;

   printf("Testing adventurer card\n");

   // Inititalize the game to get everything set up
   initializeGame(numPlayers, kc, randomSeed, &state);

   numCardsHandBefore = state.handCount[0];

   // Play the card and see what happens!
   test = cardEffect(card, choice1, choice2, choice3, &state, handPos, &bonus);

   printf("Testing if adventurer played correctly:\t");
   numBugs += comp(test == 0);

   numCardsHandAfter = state.handCount[0];

   printf("Number of cards in hand before: %d\t and after: %d\t", 
            numCardsHandBefore, numCardsHandAfter);
   numBugs += comp(numCardsHandBefore + 2 == numCardsHandAfter);

   if (numBugs == 0)
   {
      printf("No bugs were found in adventurer card!\n");
   }
   else
   {
      printf("Found %d bugs in adventurer card!\n", numBugs);
   }

   return 0;
}
