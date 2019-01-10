/*
Devante Wilson - 100554361
Shahrukh Zarir - 100489271

October 3, 2016
Systems Programming
Lab 2 - Task 2

Program reads text file data
and replaces target phrases with
another corresponding output.

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
	char inputData[1000], tempLineData[200], tempDataAfter[200];	// file data
	char *targetPhrases[9], *outputPhrases[9]; // data array pointers
	char *index; // hold index of word found
	int word, a, b, c;	// array counters
	int size1, size2, size3; // line positions
	int targetSize;	// length of target phrase

	// initialize data arrays
	targetPhrases[0] = "Inferno";
	targetPhrases[1] = "In dark woods";
	targetPhrases[2] = "those woods";
	targetPhrases[3] = "to enter";
	targetPhrases[4] = "crest";
	targetPhrases[5] = "Below a hill";
	targetPhrases[6] = "shoulders";
	targetPhrases[7] = "planet";
	targetPhrases[8] = "dante";

	outputPhrases[0] = "Paradisio";
	outputPhrases[1] = "using Windows 8.1";
	outputPhrases[2] = "Windows 8.1";
	outputPhrases[3] = "to use 8.1";
	outputPhrases[4] = "screen";
	outputPhrases[5] = "Before a monitor";
	outputPhrases[6] = "GUI";
	outputPhrases[7] = "UNIX";
	outputPhrases[8] = "Shakespeare";
	
	// verify arguments passed in at run-time
	if (argc != 2) 
	{	
		// report argument count error
		printf("Too little or too many arguments passed in.\n");
		// terminate program
		exit(0);
	}
	
	// attempt to open file for reading
	if ((fpt1 = fopen("Input.txt", "r")) == NULL)
	{	
		// report file reading error
		printf("Unable to open %s for reading.\n", argv[1]);
		// terminate program
		exit(0);
	}
	// open new text file for writing
	fpt2 = fopen("Dante.txt", "w");
	
	// scan/read original text file line by line
	while (fgets(inputData, 200, fpt1) != NULL)
	{	
		// iterate and attempt to find instance of target phrases
		for (word = 0; word < 9; word++)
		{	
			//strcpy(tempLineData, strstr(inputData, targetPhrases[word]));
			if ((index = strstr(inputData, targetPhrases[word])) != NULL)
			{
				// store length of target phrase found
				targetSize = strlen(targetPhrases[word]);
				
				// size of target with original data following
				size1 = strlen(index);
				// full line length of original data
				size2 = strlen(inputData);
				// size of phrase before target
				size3 = size2 - size1; 
				
				// initialize array counter
				c = 0;
				
				// copy inputted line to temporary data collection
				for (a = 0; a < size3; a++)
				{
					tempLineData[a] = inputData[a];
				}
		
				// set end of string
				tempLineData[a] = '\0';

				// append new output phrase to end of original line data
				strcat(tempLineData, outputPhrases[word]);
				
				// add remaining original line data
				for (b = size3 + targetSize; b < size2; b++)
				{
					tempDataAfter[c] = inputData[b];
					c++;
				}
				
				// set end of string
				tempDataAfter[c] = '\0';
				// append remaining original line data to modified line data
				strcat(tempLineData, tempDataAfter);
				// replace original line data with modified line data
				strcpy(inputData, tempLineData);
			}
		}
	
		// write modified data into new text file
		fprintf(fpt2, "%s ", inputData);
	}

	// close files
	fclose(fpt1);
	fclose(fpt2);

	return (0);
}
