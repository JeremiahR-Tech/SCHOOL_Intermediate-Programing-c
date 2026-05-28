#include <stdio.h>

int main()
{
	/* This program will accept an A and B integer
	from the user and return different logic results*/

	int a = 0, b = 0;
	
	// Getting user input
	printf("Enter in the A & B value (1 = true and 0 = false): ");
	scanf("%d %d",&a,&b);
	
	// Time to check the and logic!
	if ((a && b) == 1)
	{
		printf("A && B = %d\n", a&&b);
	}
	else
		printf("A && B is false\n");
	
	
	// Time to check the and logic!
	if ((a || b) == 1)
	{
		printf("A || B = %d\n", a||b);
	}
	else
		printf("A || B is false\n");

	
	// Time to check the and logic!
	if ((!(a || b)) == 1)
	{
		printf("!(A || B) = %d\n", (!(a||b)));
	}
	else
		printf("!(A || B) is false\n");

	return 0;
}
