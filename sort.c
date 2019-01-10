/*
Devante Wilson - 100554361
Shahrukh Zarir - 100489271

November 22, 2016
Systems Programming
Lab 5 - Task 2

Program prompts user for a number of integers
and sorts them into ascending order using
the bubble sort algorithm.
*/

// import files
#include <stdio.h>
#include <stdlib.h>

// bubble sort algorithm
void bubbleSort(int elementAmount, int arr[])
{
	int temp;	// temporary storage variable
	int swap = 1;	// notice to keep passing through array
	//size_t size = sizeof arr / sizeof arr[0];

	// start first full iteration
	while (swap)
	{
		// await possible swap
		swap = 0;

		for (int a = 0; a < elementAmount - 1; a++)
		{
			// ascending sort
			if (arr[a] > arr[a + 1])
			{
				temp = arr[a];
				arr[a] = arr[a + 1];
				arr[a + 1] = temp;
				swap = 1;	// swap occurred
			}
		}
	}
}

// conduct execution at run time
int main(int argc, char *argv[])
{
	// declare variables/objects
	int inputAmount;		// amount of elements user wants to enter 
	int defaultAmount;		// default number of elements
	int *inputIntegers;		// store integers entered by user
	int index;				// array index
	char exitKey;			// character used when user prompted to exit

	// initialize default number of elements to allocate
	defaultAmount = 50;

	// allocate some memory by default
	inputIntegers = malloc(defaultAmount * sizeof(int));

	// prompt user for amount of integers
	printf("Enter number of elements:\n");
	scanf("%d", &inputAmount);

	// prompt user for integer data
	printf("Enter %i integers:\n", inputAmount);

	// reallocate memory if needed
	if (inputAmount > defaultAmount)
		inputIntegers = realloc(inputIntegers, inputAmount * sizeof(int));

	// iterate through array
	for (index = 0; index < inputAmount; index++)
	{
		// fill array with user input
		scanf("%d", &inputIntegers[index]);
	}

	// call method
	bubbleSort(inputAmount, inputIntegers);

	// print result
	printf("Sorted list in ascending order:\n");
	// iterate through array
	for (index = 0; index < inputAmount; index++)
	{
		// print sorted integers in ascending order
		printf("%d\n", inputIntegers[index]);
	}

	// return value
	return 0;
}
