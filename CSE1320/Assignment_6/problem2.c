/*Jeremiah Richard
CSE1320
Professor Dillhoff
10/30/2021
Assignment 6, problem2 */

#include "problem2.h"
#define BUF_SIZE 1024

void trim(char *buff)
{
	int l = strlen(buff);
	if(buff[l-1] == '\n')
	{
		buff[l-1] = 0;
	}
}

void readtxt(FILE *tfp)
{

	char buffer[BUF_SIZE] = { 0 };
	char return_str[6] = "return";
	int buf_len = 0;
	int tab_count = 0; // Will use this to calculate how many tabs.

	int test_num = strcmp(return_str,buffer);
// Test---	printf("Test Num: %d\n",test_num);

	while(1)
	{
		fgets(buffer, BUF_SIZE,tfp);
		if(feof(tfp))
		{
			break;
		}
		trim(buffer);
		buf_len = strlen(buffer);
	// Test---	printf("Buffer Length: %d\n",buf_len);
	// Test--	printf("Buffer: %s\n",buffer);

		if(buffer[buf_len - 1] == ')')
		{
//			printf("Tab Count: %d\n",tab_count);
			for(int i = 0;!(i == tab_count);i++)
			{
				putchar('\t');
			}
			printf("%s\n",buffer);
			tab_count++;
		}
		else if((strcmp(return_str,buffer)) == test_num)
		{
//			printf("In return else if!\n");
			tab_count--;
		}
	}
}

int main(int argc,char **argv)
{
	if(!(argc == 2))
	{
		printf("ERROR. USAGE: ./a.out FILENAME\n");
		return 1;
	}

	// Intializing variables...filename first
	int filename_size = 0;
	filename_size = strlen(argv[1]);
	char *filename = calloc((filename_size+1),sizeof(char));
	strcpy(filename,argv[1]);

	FILE *tfp = fopen(filename,"r");

	if(!tfp)
	{
		printf("Could not open file.\n");
		return 1;
	}

// Test---	printf("Filename: %s\n", filename);

	readtxt(tfp);

	fclose(tfp);
	free(filename);

	return 0;
}
