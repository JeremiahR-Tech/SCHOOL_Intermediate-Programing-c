#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*Jeremiah Richard
ID: 1001475742
Professor Dillhoff
CSE 1320-001
Assignment 3, Problem 1 (bit_sequence)
9/25/2021 */

int find_seq(unsigned char byte,int seq_num)
{
	int  byte_count = 0; // Going to be the count of 1's together in this byte
	int tally = 0; // Will tally each 1 in a row
	for(int i = 7;i >= 0;i--)
	{

		if((byte >> i) & 1)
		{
			tally++;
			if(tally == seq_num)
			{
				byte_count++;
				tally = 0;
			}
		}
	}
	return byte_count;
}

int read_binary(FILE *fp, int seq_num)
{

	unsigned char byte = 0;
	int count = 0;

	while(fread(&byte,sizeof(unsigned char),1,fp))
	{
		count = count + (find_seq(byte,seq_num));
	}

	/*-- T E S T--printf("Count right after read_binary: %d\n",count);*/

	return count;
}

// This function will accept a file and integer to count number of sequence of n
int read_ones(char *filename, int seq_num)
{
	FILE *bit_file = fopen(filename, "rb");

	// Intializing counter for amount of ones in sequence
	int count = 0;

	// Checking if file is open
	if(!bit_file)
	{
		printf("Cannot open file. \n");
		return 0;
	}
	// Bread and butter of the programing to read from the file for sequences of one
	count = read_binary(bit_file,seq_num);

	fclose(bit_file);

	// Want this function to return the number of ones together counted
	return count;
}


int main(int argc, char **argv)
{

	// Intializing variables
	int num = 0; // Will use to know how many ones to sequence
	char *filename = argv[1];
	
	/* 
	Note: argv[1] will be the file
	Note: argv[2] will be the number for one's sequence */

	if (argc != 3)
	{
		printf("ERROR! Incorrect Input!\n");
		printf("USAGE: ./a.out FILENAME NUMBER\n");
		return 1;
	}

	/* -- TEST -- This is to see what arguments are stored in program 
	for(int = 0; i < 3;)
	{
		printf("argv[i] = %s\n",i, argv[1]);
	}*/

	printf("Filename: %s\n",argv[1]);

	// Storing values from command line properly
	num = atoi(argv[2]);
	printf("num = %d\n",num);

	printf("Count = %d\n", read_ones(filename,num));

	return 0;
}
