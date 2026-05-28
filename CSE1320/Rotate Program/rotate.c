#include <stdio.h>

char rotate(char x, int add)
{
	x = (x + add - 33)%(126-33+1);
	x += 33;
	return x;
}

int main ()
{
	//intializing variables
	char x;
	int add = 0;	
	
	do
	{
		
		printf("> "); 
		scanf("%c%d", &x, &add);
	
		if ((x<33) || (x>126))
                {
                        printf("Error! Your character and number combination  is out the ASCII [33 - 126] range!");
                }

	}while ((x<33) || (x>126));

	x = rotate(x,add);

	if(x<33)
	{
		x = 126 + add+1;	
	}
	else if(x>126)
	{
		x = 33 - add+1;
	}

        printf("\n%c\n", x);

	return 0;
}
