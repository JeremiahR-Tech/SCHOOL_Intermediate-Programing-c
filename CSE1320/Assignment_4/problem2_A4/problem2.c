/*Jeremiah Richard
CSE1320.001
Professor Dillhoff
10/7/2021 
Assignment 4, problem 2 */

#include "problem2.h"

// Resizing memory here! Got to be careful with reallocating...

dynamic_array rm_value(int rm_index,dynamic_array buddy)
{
	if(!(buddy.size == 0))
	{
		if((rm_index < 0) || (rm_index > (buddy.size -1))) // Can't have crazy indexes
		{
			printf("Invaild Index...\n");
			return buddy;
		}
		else
		{
			buddy.data[rm_index] = 0;
			for(int i = rm_index;i < (buddy.size-1);i++)
			{
				buddy.data[i] = buddy.data[i+1];
			}
			buddy.size--;
		}
	}
	else
	{
		printf("You don't have anything in the array!\n");
		return buddy;
	}
	// Remember to reallocate before you leave!
	buddy.data = realloc(buddy.data, buddy.size * (sizeof(double)));

	for(int i = 0;i < buddy.size;i++)
	{
		printf("Array[%d] = %g\n",i,buddy.data[i]);
	}
	printf("Array Size = %d\n",buddy.size);


	return buddy;
}

// Using dynamic memory here, need to also free in main and check if memory was alloated
dynamic_array add_value(double value, dynamic_array buddy)
{

	buddy.data = realloc(buddy.data, (buddy.size+1) * (sizeof(double)));

	// Have to check when you can't make an array at all
	if(buddy.data == NULL)
	{
		printf("Couldn't add add to the array at all, try again :( \n");
		return buddy;
	}
	else
	{
		buddy.size++;
//		printf("Right before adding to array\n");
		buddy.data[buddy.size-1] = value;

		for(int i = 0; i < buddy.size; i++)
		{
			printf("Array [%d] = %g\n",i,buddy.data[i]);
		}
		printf("Array Size: %d\n", buddy.size);
	}

	return buddy;
}

int main()
{

	// Intializing variables
	dynamic_array buddy = { 0 };
	int choice = 0, rm_index = 0;
	double value = 0;

	// This will be the meat of the program allowing the user choice
	do
	{

		// Getting the user input for choice
		printf("1. Add Value\n");
		printf("2. Remove Value\n");
		printf("3. Exit\n");
		printf("> ");

		scanf("%d",&choice);

/*		printf("TEST - Choice: %d\n",choice); */

		switch(choice)
		{
			case(1): // Add value
			{
//				printf("TEST - In case 1\n");

				printf("Enter a value: ");
				scanf("%lf", &value);
				buddy = add_value(value,buddy);
				break;
			}
			case(2): // Remove Value
			{
//				printf("TEST - In case 2\n");

				printf("Enter an index: ");
				scanf("%d",&rm_index);
				buddy = rm_value(rm_index,buddy);
				break;
			}
			case(3): // Exit
			{
//				printf("TEST - In case 3\n");
				if(!(buddy.data == NULL))
				{
					free(buddy.data);
				}
				break;
			}
			default:
				printf("Invalid command.\n");
		}
	}while(!(choice == 3));


	return 0;
}
