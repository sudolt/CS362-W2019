/*******************************************************************************
 *
 * Name:    Tim Sudol
 * Class:   CS362 - Winter 2019
 * Date:    26 JAN 2019
 * Program: unittest3.c
 *
 * This program verifies the function updateCoins in dominion.c.  
 *
 * The strategy is to set the hands of each player into certain combinations
 * of treasure cards and non-treasure cards to look for any bugs in the
 * function.
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

   // Expected coin return
   int expectedCoin;

   // The structure that holds the game
   struct gameState state;

   state.handCount[0] = 10;

   printf("Testing updateCoins\n");

   // Set the hand up for one copper
   expectedCoin = 1;
   state.hand[0][0] = copper;
   for (int i = 1; i < 10; ++i)
   {
      state.hand[0][i] = mine;
   }

   printf("Testing 1 copper in card 0\n");
   updateCoins(0, &state, 0);
   numBugs += comp(expectedCoin == state.coins);

   // Reset the hand to all mines, then manually change cards 5 and 6
   for (int i = 0; i < 10; ++i)
   {
      state.hand[0][i] = mine;
   }
   state.hand[0][4] = copper;
   state.hand[0][5] = copper;
   expectedCoin = 2;
   printf("Testing 2 copper in card slots 5 and 6\n");
   updateCoins(0, &state, 0);
   numBugs += comp(expectedCoin == state.coins);

   // Reset the hand to all mines, then manually change cards 8, 9, and 10
   for (int i = 0; i < 10; ++i)
   {
      state.hand[0][i] = mine;
   }
   state.hand[0][7] = copper;
   state.hand[0][8] = copper;
   state.hand[0][9] = copper;
   printf("Testing 3 copper in card slots 8, 9, and 10\n");
   expectedCoin = 3;
   updateCoins(0, &state, 0);
   numBugs += comp(expectedCoin == state.coins);

   // Reset the hand to all mines, then manually change cards 2, 4, 6, and 7
   for (int i = 0; i < 10; ++i)
   {
      state.hand[0][i] = mine;
   }
   state.hand[0][2] = copper;
   state.hand[0][6] = copper;
   state.hand[0][7] = copper;
   state.hand[0][4] = copper;
   printf("Testing 4 copper in card slots 3, 5, 7 and 8\n");
   expectedCoin = 4;
   updateCoins(0, &state, 0);
   numBugs += comp(expectedCoin == state.coins);

   // Check out silver calculations.  Each silver is worth 2 coins
   expectedCoin = 2;
   for (int i = 0; i < 10; ++i)
   {
      state.hand[0][i] = mine;
   }
   state.hand[0][5] = silver;
   printf("Testing 1 silver in card 6\n");
   updateCoins(0, &state, 0);
   numBugs += comp(expectedCoin == state.coins);

   expectedCoin = 4;
   for (int i = 0; i < 10; ++i)
   {
      state.hand[0][i] = mine;
   }
   state.hand[0][3] = silver;
   state.hand[0][7] = silver;

   printf("Testing 2 silver in cards 4 and 8\n");
   updateCoins(0, &state, 0);
   numBugs += comp(expectedCoin == state.coins);

   // On to gold!
   // each is worth 3 coins 
   expectedCoin = 3;
   for (int i = 0; i < 10; ++i)
   {
      state.hand[0][i] = mine;
   }
   state.hand[0][8] = gold;
   printf("Testing 1 gold in card 9\n");
   updateCoins(0, &state, 0);
   numBugs += comp(expectedCoin == state.coins);

   expectedCoin = 6;
   for (int i = 0; i < 10; ++i)
   {
      state.hand[0][i] = mine;
   }
   state.hand[0][1] = gold;
   state.hand[0][9] = gold;

   printf("Testing 2 gold in cards 2 and 10\n");
   updateCoins(0, &state, 0);
   numBugs += comp(expectedCoin == state.coins);

   // Time to check mixtures of treasure
   // one copper and one silver
   expectedCoin = 3;
   for (int i = 0; i < 10; ++i)
   {
      state.hand[0][i] = mine;
   }
   state.hand[0][6] = copper;
   state.hand[0][0] = silver;
   printf("Testing 1 copper in card 6 and 1 silver in card 1\n");
   updateCoins(0, &state, 0);
   numBugs += comp(expectedCoin == state.coins);

   // one copper and one gold
   expectedCoin = 4;
   for (int i = 0; i < 10; ++i)
   {
      state.hand[0][i] = mine;
   }
   state.hand[0][2] = gold;
   state.hand[0][4] = copper;

   printf("Testing 1 copper in card 5 and one gold in card 3\n");
   updateCoins(0, &state, 0);
   numBugs += comp(expectedCoin == state.coins);

   // one copper, one silver, and one gold
   expectedCoin = 6;
   for (int i = 0; i < 10; ++i)
   {
      state.hand[0][i] = mine;
   }
   state.hand[0][3] = gold;
   state.hand[0][8] = silver;
   state.hand[0][6] = copper;

   printf("Testing 1 copper in card 7, gold in 4 and silver in in card 9\n");
   updateCoins(0, &state, 0);
   numBugs += comp(expectedCoin == state.coins);

   // now checking if all cards have coin
   state.hand[0][0] = copper;
   state.hand[0][1] = silver;
   state.hand[0][2] = gold;
   state.hand[0][3] = silver;
   state.hand[0][4] = copper;
   state.hand[0][5] = copper;
   state.hand[0][6] = silver;
   state.hand[0][7] = silver;
   state.hand[0][8] = gold;
   state.hand[0][9] = gold;
   expectedCoin = 20;
   printf("Testing 3 copper, 4 silver, and 3 gold\n");
   updateCoins(0, &state, 0);
   numBugs += comp(expectedCoin == state.coins);

   // no coins in hand at all
   expectedCoin = 0;
   for (int i = 0; i < 10; ++i)
   {
      state.hand[0][i] = mine;
   }
   printf("Testing no coins in hand\n");
   updateCoins(0, &state, 0);
   numBugs += comp(expectedCoin == state.coins);

   if (numBugs == 0)
   {
      printf("No bugs were found in updateCoins!\n");
   }
   else
   {
      printf("Found %d bugs in updateCoins!\n", numBugs);
   }

   return 0;
}
