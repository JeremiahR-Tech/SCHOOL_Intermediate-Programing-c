
#include <stdio.h>
#include <string.h>


/*Jeremiah Richard
ID: 1001475742
Professor Dillhoff
CSE 1320-001
Assignment 2, Problem 2
Date: 9/16/2021 */

int count = 0; //Count will count number of strings
#define SIZE  128
#define SIZE_S  4

/*This is the main part of the code which will actually
rotate the strings based on the integer given by the user
and print. This function will therefore accept a pointer array for char
and an integer value. */
void rotate(char **strings,int rot)
{
	char med[SIZE]; // Will be used in rotating
	int turn_base = 0; // This is how far back you will go to get your answer instead of forward
	int itt_even = 0; // This is for each itteration of an even number
	 //Count will be use for numbers over amount of strings

	int swap_num = 0; // I will use this for cases outside of the string limits

	/* -- T E S T -- checking if the code enters rotate. 
	printf("Program is in rotate function\n"); */

	if((rot <= count) && ((rot % 2) == 0))
	{
		itt_even = rot/2;
		if((itt_even%2) == 0)
		{
			rot = 0;
			printf("Got here in even itt\n");
		}
		else if((itt_even%2) == 1)
		{
			rot = 2;
			printf("Got here in odd itt\n");
		}
		printf("I was here\n");
	}
	else if((rot >= count))
	{
		rot  = rot % count;
	}

	turn_base = rot - count;

	int k = 0; // Itterations of rotation process
	// K will change depending on amount of string count
	if((count%2) == 0)
	{
		k = 1;
	}

	for(k = 0; k < rot;k++)
	{
		for(int i = (count-1);i > 0;i--)
		{
				// If is for going out of string limits below zero
				if ((i+turn_base) < 0)
				{
					swap_num = turn_base +  count;
					strcpy(med,strings[i+swap_num]);
					strcpy(strings[i+swap_num],strings[i]);
					strcpy(strings[i],med);
				}
				else
				{
					strcpy(med,strings[i+turn_base]);
					strcpy(strings[i+turn_base],strings[i]);
					strcpy(strings[i],med);
				}
		}
	}

	//This is used to test if the string copying worked correctly.
	for(int i = 0;i<SIZE_S;i++)
	{
		/*I will copy and use the first character of array
		to test string to find a null array.
		Then I can avoid printing null strings.*/
		char test [SIZE];
		strcpy(test,strings[i]);

		if(test[0] != '\n')
		{
			printf("%s\n",strings[i]);
		}
	}
}

/* This code is the second problem in assignement 2 and 
should read four strings and an integer inputed by the user then
rotate the strings by that integer */ 

// This will trim the new line character from each string
void trim(char *str)
{
	int l = strlen(str);
	if (str[l-1] == '\n')
	{
		str[l-1] = 0;
	}
}

// This will check for enter in our strings
int check_enter(char stg[], int size)
{
	int flag = 0;
	if(stg[0] == '\n')
		flag = 1;

	return flag;
}

int main()
{
	// Intialzing variables
	int rot = 0, flag = 1;
	char stg1[SIZE],
	stg2[SIZE],
	stg3[SIZE],
	stg4[SIZE];
	
	memset(stg1,'\0',sizeof(stg1));
	memset(stg2,'\0',sizeof(stg2));
	memset(stg3,'\0',sizeof(stg3));
	memset(stg4,'\0',sizeof(stg4));
	

	char *strings[SIZE_S];
	strings[0] = stg1;
	strings[1] = stg2;
	strings[2] = stg3;
	strings[3] = stg4;
	
	// Get user input for string 1
	printf("Enter a string: ");
	fgets(stg1,SIZE,stdin);
	

	/* Using if statements to stop code if an
	empty string is caught by the user*/
	if (flag  == check_enter(stg1,SIZE))
	{
		//printf number of strings read
		printf("Got no strings :(\n");
		count = 0;
	}
	else
	{
		// Triming before next string
		trim(stg1);

		// Get user input for string 2
        	printf("Enter a string: ");
        	fgets(stg2,SIZE,stdin);
		
		if (flag == check_enter(stg2,SIZE))
		{
			printf("Got one strings!\n");
			count = 1;
		}
		else
		{
			trim(stg2);
			
        		// Get user input for string 3
        		printf("Enter a string: ");
        		fgets(stg3,SIZE,stdin);

			if (flag == check_enter(stg3,SIZE))
			{
				printf("Got two strings!\n");
				count = 2;
			}
			else
			{
				trim(stg3);

				// Get user input for string 4
        			printf("Enter a string: ");
        			fgets(stg4,SIZE,stdin);
				
				if (flag == check_enter(stg4,SIZE))
				{
					printf("Got three strings!\n");
					count = 3;
				}
				else
				{
					trim(stg4);

					printf("Got four strings!\n");
					count = 4;
				}
			}
		}
	}
	
	/*  --T E S T--
	This test checks if the string and
	integer variables are stored
	printf("%s\n",stg1);
	printf("%s\n",stg2);
	printf("%s\n",stg3);
	printf("%s\n",stg4);
	*/

	// Input for integer
	printf("Enter a number: ");
	scanf("%d",&rot);

	/* --T E S T--

	printf("Program is right before rotate is called.\n");
	printf("%s\n",strings[0]);
	printf("%s\n",strings[1]);
	printf("%s\n",strings[2]);
	printf("%s\n",strings[3]); */

	rotate(strings,rot);

	// Exit Code
	return 0;
}
