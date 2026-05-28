#include <stdio.h>

//Making a struct to clean up variables
typedef struct
{
	int x;
	int y;
	int radius;
	int ptN;  //farthest point up
	int ptE; //farthest point right
	int ptS; //farthest point down
	int ptW; //farthest point left
} circle;

/*Return a void function because the function does
 a printing action after checking if the circle have the same value */
void overlap(circle A, circle B)
{
	
	//intializing the points of the circle
	A.ptN = A.y + A.radius; //farthest point up
        A.ptE = A.x + A.radius; //farthest point right
        A.ptS = A.y - A.radius; //farthest point down
        A.ptW = A.x - A.radius; //farthest point left

	B.ptN = B.y + B.radius; //farthest point up
        B.ptE = B.x + B.radius; //farthest point right
        B.ptS = B.y - B.radius; //farthest point down
        B.ptW = B.x - B.radius; //farthest point left
	

	//Once we know which one is bigger we can print if an overlap is detected
	if ((B.ptN < A.ptN)&&(B.ptE < A.ptE)&&(B.ptS > A.ptS)&&(B.ptW > A.ptW))
	{
			printf("Overlap detected!\n");
	}
	else if ((A.ptN < B.ptN) && (A.ptE < B.ptE) && (A.ptS > B.ptS) && (A.ptW > B.ptW))
	{
			printf("Overlap detected!\n");
	}
	else
	{
		printf("No overlap.\n");
	}
}

int main()
{
	//intializing the variables of a circle
	circle A;
	circle B;

	//Getting the user output for the first circle
	printf("Enter circle 1 parameters (x y radius): ");
	scanf("%d%d%d", &A.x, &A.y, &A.radius);
	
	printf("Enter circle 2 parameters (x y radius): ");
	scanf("%d%d%d", &B.x, &B.y, &B.radius);

	//Lets see if the the two cirlces overlap!
	overlap(A,B);
	
	//Exiting code
	return 0;
}

