//Sophia Muller
// CISP 360
// 13 April, 2015
// Extra Credit: Dynamic Array Practice

#include <stdio.h>
#include <stdlib.h>

void displayArray(int *ptd, int arraySize);
void displayBytes(int arraySize, int bytes);
void changeArray(int *ptd, int oldMax, int doubleOrHalve);
int main(void)
{
	int * ptd; // points to array
	int max = 0;
	int memorySize = 0;
	int myNum = 0; // add or subtract entries to max
	int newMax = 0;
	int arraySize;
	int i= 0;
	int j = 0;
	int bytes = 0;
	
	// get max:
	puts("Enter size of array:");
	if (scanf("%d", &max) != 1)
	{
		puts("Incorrect entry; bye.");
		exit(EXIT_FAILURE);
	}
	// create array:
	ptd = (int *) malloc(max * sizeof (int)); 
	bytes = max * sizeof(int);
	if (ptd == NULL)
	{
		puts("Memory allocation failed. Bye.");
		exit(EXIT_FAILURE);
	}
	// fill array:
	puts("Enter values (q to quit):");
	while (i< max && scanf("%d", &ptd[i]) == 1)
	{		
		++i;
	}
	// display array:
	arraySize = i;
	displayArray(ptd, arraySize);
	displayBytes(arraySize, bytes);
	// modify array:
	memorySize = arraySize;
	puts("Enter # of elements to add or subtract to array (q to quit, negative number to subtract): ");
	while (scanf("%d", &myNum) == 1 && myNum != 0) // adding/subtracting 0 wouldn't make sense
	{
		if (myNum > 0) // add elements to array
		{
			// i = memorySize; // start i off at the right place
			arraySize += myNum; // adjust array size
			puts("Enter values (q to quit):");			
			while (i < arraySize)
			{				
				if (i >= (.75 * memorySize)) // once new array gets 75% full
				{
					// puts("We got to the if statement.\n");
					changeArray(ptd, memorySize, 2); // pass array and size; 2 doubles array size
					memorySize *= 2; // update previousSize					
					bytes *= 2;
				}
				scanf("%d", &ptd[i]);
				++i;
			}
			displayArray(ptd, arraySize); // display new array
			displayBytes(arraySize, bytes);
		}
		else if (myNum < 0) // subtract elements from array
		{
			// previousSize = arraySize;
			arraySize += myNum; // myNum is negative already, so don't subtract it 
			i += myNum; // update i			
			changeArray(ptd, arraySize, 1); // this might be redundant...	
			if (arraySize <= (.25 * memorySize)) // if new array size gets less than 25% of the old one
				{
					// puts("We got to the if statement.\n");
					changeArray(ptd, arraySize, .5); // pass array, old size, half
					bytes *= .5;
				}	
			displayArray(ptd, arraySize);	
			displayBytes(arraySize, bytes);
		}
		puts("Enter # of elements to add or subtract to array (q to quit, negative number to subtract): ");
	}
	puts("Done.");
	free(ptd);
	return 0;
}

void changeArray(int *ptd, int oldMax, int doubleOrHalve)
{
	// puts("We got to the function.");
	int * temp;
	temp = (int *) realloc(ptd, doubleOrHalve * oldMax * sizeof(int)); // can't get past here
	// puts("We got past realloc()\n");
	if (temp == NULL) 
	{
 	   puts("Whoops, problem with moveArray.");
	} 
	else 
	{
    	ptd = temp;
		// puts("Yay, we got stuff moved!\n");
	}
}

void displayArray(int *ptd, int arraySize)
{
	int i;
	printf("Here are your %d entries:\n", arraySize);
	for (i = 0; i < arraySize; i++)
	{
		printf("%7.2d ", ptd[i]);
		if (i % 7 == 6)
			putchar('\n');
	}
	if (i % 7 != 0)
		putchar('\n');
}

void displayBytes(int arraySize, int bytes)
{
	int occupied;
	int available;

	occupied = arraySize * sizeof(int);
	available = bytes;

	printf("Bytes currently occupied: %d\n", occupied);
	printf("Bytes available (in total): %d\n", available);
}
