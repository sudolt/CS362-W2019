/*******************************************************************************
 *
 * Name:    Tim Sudol
 * Class:   CS362 - Winter 2019
 * Date:    26 JAN 2019
 * Program: unittest2.c
 *
 * This program verifies the function whoseTurn in dominion.c.  
 *
 * The strategy is to set the value in state.whoseTurn manually and then verify
 * that the function is returning the expected value.
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

   // The number of the player that we will be setting whoseTurn it is
   int playerTurn;

   // The structure that holds the game
   struct gameState state;

   printf("Testing whoseTurn\n");

   // Setting the player directly to see if there is an issue with the return
   playerTurn = 0;
   printf("Testing player %d\n", playerTurn);
   state.whoseTurn = playerTurn;
   numBugs += comp(playerTurn == whoseTurn(&state));

   playerTurn = 3;
   printf("Testing player %d\n", playerTurn);
   state.whoseTurn = playerTurn;
   numBugs += comp(playerTurn == whoseTurn(&state));

   playerTurn = 1;
   printf("Testing player %d\n", playerTurn);
   state.whoseTurn = playerTurn;
   numBugs += comp(playerTurn == whoseTurn(&state));

   playerTurn = 5;
   printf("Testing player %d\n", playerTurn);
   state.whoseTurn = playerTurn;
   numBugs += comp(playerTurn == whoseTurn(&state));

   playerTurn = 2;
   printf("Testing player %d\n", playerTurn);
   state.whoseTurn = playerTurn;
   numBugs += comp(playerTurn == whoseTurn(&state));

   playerTurn = 9;
   printf("Testing player %d\n", playerTurn);
   state.whoseTurn = playerTurn;
   numBugs += comp(playerTurn == whoseTurn(&state));

   playerTurn = 10;
   printf("Testing player %d\n", playerTurn);
   state.whoseTurn = playerTurn;
   numBugs += comp(playerTurn == whoseTurn(&state));

   playerTurn = 0;
   printf("Testing player %d\n", playerTurn);
   state.whoseTurn = playerTurn;
   numBugs += comp(playerTurn == whoseTurn(&state));

   playerTurn = 3;
   printf("Testing player %d\n", playerTurn);
   state.whoseTurn = playerTurn;
   numBugs += comp(playerTurn == whoseTurn(&state));

   if (numBugs == 0)
   {
      printf("No bugs were found in whoseTurn!\n");
   }
   else
   {
      printf("Found %d bugs in whoseTurn!\n", numBugs);
   }

   return 0;
}
