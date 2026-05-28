#include <stdio.h>


/* This function will calcuate the four factors of an integer, print all factors of small integers and identify prime numbers */
void four_factors(int x)
{
	int fact1 = 0;
	int fact2 = 0;
	int fact3 = 0;
	int fact4 = 0;
	int flag = 0;

	//I need to use this for loop to find out if there is a prime number
	for(int i = 2; i<x; i++)
	{
		//This loop is for all non-prime numbers
		if(x%i == 0)
		{
			flag = 1;
			int greatnum = 0;
			greatnum = x/i;

			/*Store the variables...
			For the highest numbers it is easy as the lowest factor number divided will get the highest numbers. 
			For the highest numbers divided they will get the lowest factors. However to correctly gauge which lowest
			number it can be determined by 4 numbers that all numbers are factors of except one.*/
			if(fact4 == 0)
			{
				fact4 = x/i;
			}
			else if (fact3 == 0)
			{
				fact3 = x/i;
			}
			else if ((fact2 == 0) && (greatnum == 2 || greatnum == 3 || greatnum == 5 || greatnum == 7))
			{
				fact2 = greatnum;
			}
			else if ((fact1 == 0) && (greatnum == 2 || greatnum == 3 || greatnum == 5 || greatnum == 7))
			{
				fact1 = greatnum;
			}
		}
	}
	
	//Switch the flag for the 3rd case scenario
	if(fact1 == 0 || fact2 == 0 || fact3 == 0 ||  fact4 == 0)
	{
		flag = 2;
	}
	if(x == 1)
	{
		flag = 3;
	}

	/*This will determine what output need to be released base on each case.
	- Case 0 is default and is the number being prime.
	- Case 1 is the number having factors.
	- Case 2 is the number with less than four factors 
	- Case 4 is for the number 1*/
	switch (flag)
	{
		case 0:
		{
			printf("%d is prime!\n", x);
			break;
		}
		case 1:
		{
      			printf("%d\n%d\n%d\n%d\n", fact1, fact2, fact3, fact4);
			break;
		}
		case 2:
		{
			if (fact4 == 0)
			{
				printf("%d\n", fact4);
			}
			else if(fact3 == 0)
			{
				printf("%d\n", fact4);
			}
			else if(fact2 == 0)
			{
				printf("%d\n%d\n", fact3, fact4);
			}
			else if(fact1 == 0)
			{
				printf("%d\n%d\n%d\n", fact2, fact3, fact4);
			}
			break;
		}	
		case 3:
		{
			printf("%d\n", 1);
			break;
		}
	}

}

int main()
{
	//Intilizing variables
	int number = 0;

	printf("Enter the Integer: ");
	scanf("%d", &number);
	
	//printing out factors out
	four_factors(number);
	
	//To exit the code
	return 0;
}	
