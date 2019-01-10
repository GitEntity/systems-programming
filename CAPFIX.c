/*
Devante Wilson - 100554361
September 19, 2016

Lab 1
Program reads first and last names from a text file
and modifies them by correcting their upper and lower case
letters.
*/

// import libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// conduct all file reading operations
int ReadData(FILE *fpt, char first[20][30], char last[20][30]){
	// initialize total count
	int total=0;

	// read and store text file data
	while (1) {
		if (fscanf(fpt,"%s %s",last[total],first[total]) != 2)
			break;
		total++;
	}

	// close file
	fclose(fpt);

	// return total amount of complete names
	return (total);
}

// conduct all operations for modifying text file data
void CapFix(char word[30]){
	// declare variable(s)
	int i;

	// check for lower case letters and convert to uppercase
	if (word[0] >= 'a' && word[0] <= 'z')
		word[0] = word[0] - 'a' + 'A';

	// convert every letter except the first to lower case
	for (i=1; i<strlen(word); i++)
		if (word[i] >= 'A' && word[i] <= 'Z')
			word[i] = word[i] - 'A' + 'a';
}

int main(int argc, char *argv[]) {
	// declare and initialize variables/objects
	FILE *fpt;
	char first[20][30],last[20][30];
	int i,j,total;

	/* check that the amount of arguments passed in the command line
	is only equal to 2 (i.e., one first and one last name)*/
	if (argc != 2) {
		printf("Usage: CAPFIX [filename]\n");
		exit(0);
	}
	
	// check for file availability for reading
	if ((fpt=fopen(argv[1],"r")) == NULL) {
		printf("Unable to open %s for reading\n",argv[1]);
		exit(0);
	}
	
	// total amount of complete names
	total = ReadData(fpt, first, last);
	
	// call method to modify text file data
	for (i=0; i<total; i++) {
		// first names
		CapFix(first[i]);
		// last names
		CapFix(last[i]);
	}	

	// display the modified first and last names
	for (i=0; i<total; i++)
		printf("%s %s\n",first[i],last[i]);
}
