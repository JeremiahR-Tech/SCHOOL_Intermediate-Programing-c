#include <stdio.h>
#include <math.h>

/* Jeremiah Richard
ID: 1001475742
CSE 1320-001
Professor Dillhoff
Assignment 2, problem 4
9/18/2021*/

#define NORMAL 10
#define SEVEN 7

/* This function will accept short and convert
a number that's base 10 to base 7 */
short b10_to_b7(short x)
{
	short new_x = 0;

	for(short i=0;i <= 4;i++)
	{
		short holder = 0; // Will hold the number in it's respective num place
		short multiplier = 0; // Will multiple holder to correct num place
		multiplier = pow(10,i); // Getting multipler value
		holder = x%SEVEN;
		holder = holder * multiplier;
		x = x/SEVEN;
		new_x = new_x + holder;
	}
	
	x = new_x;
	return x;
}

short b7_to_b10(short x)
{
	short new_x = 0; // Will keep summation of numbers
	
	// Check bases until the 10000 place due to short data limits
	for(short i = 4;i >= 0;i--)
	{ 
		short holder = 0; // Will hold the number in it's respective num place
		holder = x/pow(10,i); // Number of number place
		new_x = new_x + (holder * pow(SEVEN,i)); // Summation
		x = x - (pow(10,i)*holder); // Going down to the next number place
	} 

	x = new_x;
	return x; //  
}

int main()
{
	// intializing variables
	short x = 0;

	// Getting user input
	printf("Enter a number in base 10: ");
	scanf("%hi",&x);

	/* -- T E S T -- to see if value was inputed in variable x
	printf("%hi\n",x);*/

	x = b10_to_b7(x);
	printf("Convert to base 7: %hi\n",x);

	x = b7_to_b10(x);
	printf("Convert base to base 10: %hi\n",x);
}
