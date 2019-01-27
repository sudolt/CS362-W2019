/*******************************************************************************
 *
 * Name:    Tim Sudol
 * Class:   CS362 - Winter 2019
 * Date:    26 JAN 2019
 * Program: unittest1.c
 *
 * This program verifies the function getCost in dominion.c.  The costs were
 * obtained from http://wiki.dominionstrategy.com/index.php/List_of_cards
 *
 * The strategy is to use the enum CARD to loop through all the cards, setting
 * the expected value from the website and comparing the returned value from
 * the function.
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

   // The expected cost of each card, helped with the copy/paste
   int expectedCost;
   printf("Testing getCost\n");

   //expectedCost = 3;   // Introduced bug to ensure the test was working correctly
   expectedCost = 0;
   printf("Testing curse, should be cost %d\n", expectedCost);
   numBugs += comp(getCost(0) == expectedCost);

   //expectedCost = 8;   // Introduced bug to ensure the test was working correctly
   expectedCost = 2;
   printf("Testing estate, should be cost %d\n", expectedCost);
   numBugs += comp(getCost(1) == expectedCost);

   expectedCost = 5;
   printf("Testing duchy, should be cost %d\n", expectedCost);
   numBugs += comp(getCost(2) == expectedCost);

   expectedCost = 8;
   printf("Testing province, should be cost %d\n", expectedCost);
   numBugs += comp(getCost(3) == expectedCost);

   expectedCost = 0;
   printf("Testing copper, should be cost %d\n", expectedCost);
   numBugs += comp(getCost(4) == expectedCost);

   expectedCost = 3;
   printf("Testing silver, should be cost %d\n", expectedCost);
   numBugs += comp(getCost(5) == expectedCost);

   expectedCost = 6;
   printf("Testing gold, should be cost %d\n", expectedCost);
   numBugs += comp(getCost(6) == expectedCost);

   expectedCost = 6;
   printf("Testing adventurer, should be cost %d\n", expectedCost);
   numBugs += comp(getCost(7) == expectedCost);

   expectedCost = 5;
   printf("Testing council room, should be cost %d\n", expectedCost);
   numBugs += comp(getCost(8) == expectedCost);

   expectedCost = 4;
   printf("Testing feast, should be cost %d\n", expectedCost);
   numBugs += comp(getCost(9) == expectedCost);

   expectedCost = 4;
   printf("Testing gardens, should be cost %d\n", expectedCost);
   numBugs += comp(getCost(10) == expectedCost);

   expectedCost = 5;
   printf("Testing mine, should be cost %d\n", expectedCost);
   numBugs += comp(getCost(11) == expectedCost);

   expectedCost = 4;
   printf("Testing remodel, should be cost %d\n", expectedCost);
   numBugs += comp(getCost(12) == expectedCost);

   expectedCost = 4;
   printf("Testing smithy, should be cost %d\n", expectedCost);
   numBugs += comp(getCost(13) == expectedCost);

   expectedCost = 3;
   printf("Testing village, should be cost %d\n", expectedCost);
   numBugs += comp(getCost(14) == expectedCost);

   expectedCost = 4;
   printf("Testing baron, should be cost %d\n", expectedCost);
   numBugs += comp(getCost(15) == expectedCost);

   expectedCost = 3;
   printf("Testing great hall, should be cost %d\n", expectedCost);
   numBugs += comp(getCost(16) == expectedCost);

   expectedCost = 5;
   printf("Testing minion, should be cost %d\n", expectedCost);
   numBugs += comp(getCost(17) == expectedCost);

   expectedCost = 3;
   printf("Testing steward, should be cost %d\n", expectedCost);
   numBugs += comp(getCost(18) == expectedCost);

   expectedCost = 5;
   printf("Testing tribute, should be cost %d\n", expectedCost);
   numBugs += comp(getCost(19) == expectedCost);

   expectedCost = 3;
   printf("Testing ambassador, should be cost %d\n", expectedCost);
   numBugs += comp(getCost(20) == expectedCost);

   expectedCost = 4;
   printf("Testing cutpurse, should be cost %d\n", expectedCost);
   numBugs += comp(getCost(21) == expectedCost);

   expectedCost = 2;
   printf("Testing embargo, should be cost %d\n", expectedCost);
   numBugs += comp(getCost(22) == expectedCost);

   expectedCost = 5;
   printf("Testing outpost, should be cost %d\n", expectedCost);
   numBugs += comp(getCost(23) == expectedCost);

   expectedCost = 4;
   printf("Testing salvager, should be cost %d\n", expectedCost);
   numBugs += comp(getCost(24) == expectedCost);

   expectedCost = 4;
   printf("Testing sea hag, should be cost %d\n", expectedCost);
   numBugs += comp(getCost(25) == expectedCost);

   expectedCost = 4;
   printf("Testing treaure map, should be cost %d\n", expectedCost);
   numBugs += comp(getCost(26) == expectedCost);

   expectedCost = -1;
   printf("Testing return function on bad card, should return %d\n", expectedCost);
   numBugs += comp(getCost(27) == expectedCost);

   if (numBugs == 0)
   {
      printf("There were no bugs in getCost!\n");
   }
   else
   {
      printf("There were bugs in %d of the cards in getCost!\n", numBugs);
   }

   return 0;
}
