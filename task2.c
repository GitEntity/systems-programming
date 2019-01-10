/*
Devante Wilson - 100554361
Shahrukh Zarir - 100489271

November 17, 2016
Systems Programming
Lab 4 - Task 2

Program uses text file from task 1 
(containing randomly generated characters)
and counts the amount of a specified character -
specified by the command line input.
*/

// import files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	// declare variables/objects
	FILE *fpt;
	char *charToFind, charFound;
	int charCount = 0;
	
	// verify arguments passed in at run-time
	if (argc != 3) 
	{	
		// report argument count error
		printf("Too little or too many arguments passed in.\n");
		// terminate program
		exit(0);
	}
	
	// attempt to open file for reading
	if ((fpt = fopen(argv[1], "r")) == NULL)
	{	
		// report file reading error
		printf("Unable to open %s for reading.\n", argv[1]);
		// terminate program
		exit(0);
	}

	// initialize character to find (specified by command line input)
	charToFind = argv[2];

	// scan text file for character instances
	while ((charFound = getc(fpt)) != EOF)
	{
		// find specified character
		if (charFound == *charToFind)
		{
			// increment characters counted
			charCount++;
		}
	}	

	// print amount of characters found
	printf("Instances of %c found = %i\n", *charToFind, charCount);	

	// close file
	fclose(fpt);

	// return value to function
	return 0;
}
