#include <stdio.h>
#include <string.h>

/* Jeremiah Richard
ID: 1001475742
Professor Dillhoff
CSE 1320 - 001
Assignment2, Problem 3
Date: 9/17/2021 */


int count = 0;
#define WORDS 10
#define LENGTH 128

/*This is where the strings will be sorted */
void sort_string(char strings[WORDS][LENGTH])
{
	char med[WORDS][LENGTH];

	for(int k = count; k > 0;k--)
	{
		for (int i = (count-1); i > 0; i--)
		{
			if((strlen(strings[i])) > (strlen(strings[i-1])))
			{
				strcpy(med[i],strings[i-1]);
				strcpy(strings[i-1],strings[i]);
				strcpy(strings[i],med[i]);
			}
		}
	}

	for(int g = 0; g < count;g++)
	{
		if(strings[g][0] != '\0')
		{
			printf("%s\n",strings[g]);
		}
	}
}


// This will trim the new line character from each string
void trim(char *str,int i)
{
	int l = strlen(str);
	if (str[l-1] == '\n')
	{
		str[l-1] = 0;
	}
} 


// This will check for enter in our strings
int check_enter(char *stg, int i)
{
	int flag = 0;
	if(stg[0] == '\n')
		flag = 1;

	return flag;
}

int main()
{


	// Intialzing variables
	int flag = 1;
	char strings[WORDS][LENGTH];
	
	// Get user input for string 1
	for(int i = 0;i<WORDS;i++)
	{
		printf("Enter a string: ");
		fgets(strings[i],LENGTH,stdin);
		if (flag == check_enter(strings[i],i))
		{
			trim(strings[i],i);
			i = 10; // Used to terminate the for loop
		}
		else
		{
			count++;
			trim(strings[i],i);
		/*     -- T E S T -- This is to see if right values are going in 
			printf("There are %d strings.\n",i+1);
			printf("Count = %d\n", count); */
		}
	}

	// Print out captured strings
	printf("There are %d strings.\n",count);

	sort_string(strings);

	// Exit Code
	return 0;
}
