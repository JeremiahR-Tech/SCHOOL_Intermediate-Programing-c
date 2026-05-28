#include "list_products.h"
/*Jeremiah Richard
ID: 1001475742
Professor Dillhoff
9/26/2021
Assignment 3, problem 3 - list_products */

// Need to be able to trim the values of the strings
void trim(char *str)
{
	int l = strlen(str);
	if ((str[l-1]) == '\n')
	{
		str[l-1] = 0;
	}
}


// This will parse each line of the csv file breaking it apart and inputing data in struct
product parse_CSV_line(char *csv_line)
{

	char *token = strtok(csv_line, ",");
	int property = 0;
	product item = { 0 };

	while(token != NULL)
	{
		switch(property)
		{
			case 0:
			{
				item.id = atoi(token);
				break;
			}
			case 1:
			{
				strcpy(item.name, token);
				break;
			}
			case 2:
			{
				item.price = atof(token);
				break;
			}
			case 3:
			{
				item.quantity = atoi(token);
				break;
			}
			default:
				break;
		}
		property++;
		token = strtok(NULL, ",");
	}
	
	return item;
}

// The program for reading the CSV
void read_CSV(char *filename)
{

/* -- TEST --	printf("Filename inside of the read_CSV function: %s\n",filename);*/

	product item  = { 0 };

	// Making file pointer and checking if it's open
	FILE *csv_file = fopen(filename, "r");
	if(!csv_file)
	{
		printf("Cannot open the file as CSV.\n");
		return;
	}

	char buffer[BUFFER_SIZE] = { 0 };

	// Reading file
	while(fgets(buffer, BUFFER_SIZE, csv_file))
	{
		trim(buffer);
		item = parse_CSV_line(buffer);
		print_product(item);
	}

	fclose(csv_file);
}

// Simple function to print our struct
void print_product(product item)
{
	printf("ID: %d\n",item.id);
	printf("Name: %s\n",item.name);
	printf("Price: %g\n",item.price);
	printf("Quantity: %d\n",item.quantity);
}

// This function will return 1 if there is a CSEP for a working binary file and 0 if there is not. 
int check_CSEP(FILE *bin)
{
	int data = 0;

	fread(&data,sizeof(int),1,bin);

	/*-- T E S T -- printf("data = 0x%d\n", data);*/

	if(data == CSEP_INT)
	{
		return 1;
	}

	return 0;
}

// Function to read a proper binary file
void read_binary(char *filename)
{

	// Making file pointer and checking if it's open
	FILE *bin_file = fopen(filename, "rb");
	if(!bin_file)
	{
		printf("Cannot open the file as a binary file.\n");
		return;
	}

	// Need to check if this file is really binary with CSEP
	if(check_CSEP(bin_file))
	{
		/*printf("This is a proper binary file!\n");*/
		product item = { 0 };
		while(1)
		{
			fread(&item,sizeof(product),1,bin_file);

			if(feof(bin_file))
			{
				return;
			}
		
			print_product(item);
		}
	}
	else
	{
		printf("This is not a proper binary file!\n");
	}

	fclose(bin_file);
}

int main(int argc,char ** argv)
{
	char csv_check[] = "csv";
	char dat_check[] = "dat";

	/*  ---- TEST ----
	 Test for what the filename is before strtok
	printf("Filename before strtok used: %s\n",filename);*/
	/*Note: argv[1] is our FILENAME */

	if(argc != 2)
	{
		printf("Incorrect Ussage.\n");
		printf("USAGE: ./a.out FILENAME (Note: Only Binary files and CSV are accepted)\n");
		return 1;
	}

	char filename [MAX_STR] = { 0 };
	strcpy(filename, argv[1]);


	// Using this to check dot extensions of file by string token
	//making check equal the file extensions...
	char *check = strtok(filename,".");
	check = strtok(NULL,"\n");


	/* ----- TEST ----- 
	Checking for the function and equalivancy of check to csv check
	printf("Length of Check = %ld\n", strlen(check));
	printf("Length of CSV = %ld\n", strlen(csv_check));
	printf("CSV string:%s\n", csv_check);

 
	Seeing if check is containing dot extensions
	printf("Check:%s\n",check);*/

	if((strcmp(check,csv_check) == 0))
	{
		printf("Filename after strktok used: %s\n",filename);
		read_CSV(argv[1]);
	}
	else if((strcmp(check,dat_check) == 0))
	{
		read_binary(argv[1]);
	}
	else
	{
		printf("ERROR! Wrong file type. This program only accept .csv and .dat extensions.\n");
		return 1;
	}
	
	return 0;
}
