#include <stdio.h>

/*Jeremiah Richard
ID: 1001475742
Professor Dillhoff
CSE 1320-001
Assignment 2, Problem 1
Date: 9/15/2021 */

//This function with accept two int pointers and swap the values they point to
void swap_pointers(int *ptr1,int *ptr2)
{
	int *med = ptr1; //Will be needed to swap the numbers
	ptr1 = ptr2;
	ptr2 = med;

	printf("%d %d\n", *ptr1, *ptr2);
}

int main()
{

	// Intialzing variables
	int x = 0, y = 0;
	int *ptr1 = &x, *ptr2 = &y;

	// Geting user input
	printf("> ");
	scanf("%d %d", &x, &y);

	// Printing
	printf("%d %d\n", x, y);
	
	// Run function and swap!
	swap_pointers(ptr1,ptr2);

	return 0;
}
