/*
Devante Wilson - 100554361
Shahrukh Zarir - 100489271

November 15, 2016
Systems Programming
Lab 4 - Task 1

Program writes random characters to another text file.
*/

// import files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "generator.h"
#include <time.h>

int main(int argc, char *argv[])
{
	// declare variables/objects
	FILE *fpt;
	clock_t startTime, endTime;
	double timeDiff;

	// open new text file for writing
	fpt = fopen("Spam.txt", "w");

	// start time of execution
	startTime = clock();

	// call method from external file
	// (generate random characters and write to text file)
	generate(fpt);

	// end time of execution
	endTime = clock();

	// calculate time difference
	timeDiff = ((double)(endTime - startTime)) / CLOCKS_PER_SEC;

	// display result
	printf("Time elapsed for generate() = %.3f seconds\n", timeDiff);

	// close file
	fclose(fpt);
}
