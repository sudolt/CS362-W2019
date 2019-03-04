/*******************************************************************************
 *
 * Name:    Tim Sudol
 * Class:   CS362 - Winter 2019
 * Date:    17 FEB 2019
 * Program: randomcardtest1.c
 *
 * This program verifies the function of the smithy card in dominion.c.  
 *
 * The strategy is to play the card and compare hand sizes before and after the
 * card was played.  The card has you draw three cards and discard one card so
 * the change in hand size after playing the card is +2, and the deck size by
 * +4.  That will be the test.
 *
 * This test will randomize the number of cards in the hand and the game seed.
 *
 ******************************************************************************/

// Include the required header files, nothing fancy is needed
#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include <time.h>

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
 //     printf("Test failed!\n\n");
      return 1;
   }

   return -1;
}

int main()
{
   // Keep track of the number of bugs
   int numBugsHand = 0;
   int numBugsDeck = 0;
   int numBugsTest = 0;
   int goodRunHand = MAX_TESTS;
   int goodRunDeck = MAX_TESTS;
   int goodRunTest = MAX_TESTS;
   int testNum = 0;
   srand(time(NULL));
   printf("Random testing of smithy card\n");


   for (testNum = 0; testNum < MAX_TESTS; ++testNum)
   {

      // Set up the variables used to call initializeGame
      int numPlayers = 2;
      int kc[10] = {adventurer, council_room, feast, copper, gold,
                     village, cutpurse, embargo, outpost, smithy};

      int randomSeed;
      struct gameState state;

      // Set up the variables used to call cardEffect
      int card = smithy;
      int choice1 = 0;
      int choice2 = 0;
      int choice3 = 0;
      int handPos = 0;
      int bonus = 0;

      // Testing variables
      int test = 0;     // See if cardEffect worked
      int numCardsHandBefore = 0;
      int numCardsHandAfter = 0;
      int numCardsDeckBefore = 0;
      int numCardsDeckAfter = 0;


      randomSeed = rand();


      // Inititalize the game to get everything set up
      initializeGame(numPlayers, kc, randomSeed, &state);

      numCardsHandBefore = state.handCount[0];
      numCardsDeckBefore = state.deckCount[0];

      // Play the card and see what happens!
      test = cardEffect(card, choice1, choice2, choice3, &state, handPos, &bonus);

      //printf("Testing if smithy played correctly:\t");
      numBugsTest += comp(test == 0);
      goodRunTest -= comp(test == 0);

      numCardsHandAfter = state.handCount[0];
      numCardsDeckAfter = state.deckCount[0];

      //printf("Number of cards in hand before: %d\t and after: %d\t", 
      //         numCardsHandBefore, numCardsHandAfter);
      numBugsHand += comp(numCardsHandBefore + 2 == numCardsHandAfter);
      goodRunHand -= comp(numCardsHandBefore + 2 == numCardsHandAfter);

      //printf("Number of cards in deck before: %d\t and after: %d\t", 
      //         numCardsDeckBefore, numCardsDeckAfter);
      numBugsDeck += comp(numCardsDeckBefore - 3 == numCardsDeckAfter);
      goodRunDeck -= comp(numCardsDeckBefore - 3 == numCardsDeckAfter);

   }

   if (numBugsTest == 0)
   {
      printf("No errors returned from cardEffect for smithy card!\n");
   }
   else
   {
      printf("%d plays had errors from cardEffect for smithy card!\n", numBugsHand);
   }
   printf("%d plays had good cardEffect returns!\n", goodRunTest);
   if (numBugsHand == 0)
   {
      printf("No bugs were found in hand count for smithy card!\n");
   }
   else
   {
      printf("%d plays had bugs in hand count of smithy card!\n", numBugsHand);
   }
   printf("%d plays had good hand counts!\n", goodRunHand);

   if (numBugsDeck == 0)
   {
      printf("No bugs were found in deck count for smithy card!\n");
   }
   else
   {
      printf("%d plays had bugs in deck count of smithy card!\n", numBugsDeck);
   }
   printf("%d plays had good deck counts!\n", goodRunDeck);
   return 0;
}
