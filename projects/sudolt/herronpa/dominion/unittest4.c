/*******************************************************************************
 *
 * Name:    Tim Sudol
 * Class:   CS362 - Winter 2019
 * Date:    27 JAN 2019
 * Program: unittest4.c
 *
 * This program verifies the function kingdomCards in dominion.c.  
 *
 * The strategy is to set the expected array and verify that kingdomCards
 * returns the same array when passed those cards.
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
   int expectedArray[10];
   int* returnedArray;

   printf("Testing kingdomCards\n");

   printf("First array, 0 - 10\n");
   for (int i = 0; i < 10; ++i)
   {
      expectedArray[i] = i;
   }
   returnedArray = kingdomCards(0, 1, 2, 3, 4, 5, 6, 7, 8, 9);

   for (int i = 0; i < 10; ++i)
   {
      numBugs += comp(expectedArray[i] == returnedArray[i]);
   }

   printf("Second array, 10 - 0\n");
   for (int i = 9; i >= 0; --i)
   {
      expectedArray[9-i] = i;
   }
   returnedArray = kingdomCards(9, 8, 7, 6, 5, 4, 3, 2, 1, 0);

   for (int i = 0; i < 10; ++i)
   {
      numBugs += comp(expectedArray[i] == returnedArray[i]);
   }

   if (numBugs == 0)
   {
      printf("No bugs were found in kingdomCards!\n");
   }
   else
   {
      printf("Found %d bugs in kingdomCards!\n", numBugs);
   }

   return 0;
}
