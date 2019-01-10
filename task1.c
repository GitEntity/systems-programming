/*
Devante Wilson - 100554361
Shahrukh Zarir - 100489271

September 30, 2016
Systems Programming
Lab 2 - Task 1

Program reads text file data
and changes every instance of "a" to "b"

The modified data is then written to another
text file.
*/

// import libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// conduct execution at run time
int main(int argc, char *argv[])
{
	// declare variables/objects
	FILE *fpt1, *fpt2;	// text file pointers
	char inputData[30][60];	// data array
	int rows, columns;	// array row and column counters
	
	// verify arguments passed in at run-time
	if (argc != 2) 
	{	
		// report argument count error
		printf("Too little or too many arguments passed in.\n");
		// terminate program
		exit(0);
	}
	
	// attempt to open file for reading
	if ((fpt1 = fopen(argv[1], "r")) == NULL)
	{	
		// report file reading error
		printf("Unable to open %s for reading.\n", argv[1]);
		// terminate program
		exit(0);
	}

	// open new text file for writing
	fpt2 = fopen("Heaven.txt", "w");

	// initialize array row counter
	rows = 0;

	// scan/read original text file
	while (fscanf(fpt1, "%s ", inputData[rows]) != EOF)
	{	
		// iterate through each word's character
		for (columns = 0; inputData[rows][columns] != '\0'; 
			columns++)
		{	
			// check for instances of 'a' character
			if (inputData[rows][columns] == 'a')
			{	
				// change instances of 'a' to 'b'
				inputData[rows][columns] = 
					inputData[rows][columns] - 'a' + 'b';
			}
		}

		// write modified data into new text file
		fprintf(fpt2, "%s ", inputData[rows]);

		// increment counter for array
		++rows;
	}
	
	// close files
	fclose(fpt1);
	fclose(fpt2);

	// return value to main
	return 0;
}
