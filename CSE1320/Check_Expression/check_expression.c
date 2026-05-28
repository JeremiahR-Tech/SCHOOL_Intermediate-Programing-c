#include <stdio.h>
#include <string.h>



/*This function will check if an expression with 3 integers 
and two operators is correct is a correct expression as a void
return since this is a task-base function.*/
void check_expression(char express[], int length)
{

	int flag = 0;

	for(int i=0;i<length;i++)
	{
		if((express[i] == '*') || (express[i] == '+') || (express[i] == '-') || (express[i] == '/'))
		{
			//If the character before an operator is not a number or space
			if((express[i-1] < 48)|| (express[i-1]>57))
			{
				flag = 1;
			}
		}
	}

	if(flag == 1)
	{
		printf("This is an invaild expression.\n");
	}
	else
		printf("This is a valid expression.\n");		
}


int main()
{
	int length = 100;
	char express[length];

	//Getting user input of integers and operations
	printf("> ");
	scanf("%s", express);

	check_expression(express, length);

	return 0;
}
