#include "problem1.h"

/* Jeremiah Richard
CSE1320.001
Professor Dillhoff
Assignment 4, problem 1
10/5/2021 */

void alloate_int(int value)
{
	int *ptr = NULL;
	ptr = malloc(sizeof(int));

	if(ptr)
	{
		*ptr = value;
/* Test ---		printf("int_ptr = %d\n", *ptr); */
	}

	free(ptr);

}
void alloate_intarr(int value,int N)
{

	int *ptr = calloc(N, sizeof(int));

	if(ptr)
	{
		for(int i = 0;i < N;i++)
		{
			ptr[i] = value;
	/*	Test ---	printf("intarr_ptr[%d] = %d\n",i,ptr[i]); */
		}
	}

	free(ptr);

}
void alloate_2dintarr(int value,int M,int N)
{
	/* Malloc intalize a pointer so you have to set
	the pointer in your array */
	int *ptr[M];
	
	// Intializing ptr arr
	for(int i = 0;i < M;i++)
	{
		ptr[i] = NULL;
	}
	
	for(int i = 0;i < M;i++)
	{
		ptr[i] = (int *)malloc(M *sizeof(int));
	}

	for(int i = 0;i < M;i++)
	{
		if(ptr[i])
		{
			for(int j = 0;j < N;j++)
			{
				ptr[i][j] = value;
	// Test----			printf("2dintarr_ptr[%d][%d] = %d\n",i,j,ptr[i][j]);
			}
		}	
	}

	for(int i = 0;i<M;i++)
	{
		free(ptr[i]);
	}

}
void alloate_3dintarr(int value,int B,int M,int N)
{

	/* Calloc intalize a row so you have
	to set up a row */
	int *ptr[B][M];
	
	// Intializing ptr arr
	for(int i = 0;i < B;i++)
	{
		for(int j = 0;j < M;j++)
		{
			ptr[i][j] = NULL;
		}
	}

/* Test ----	printf("Make it pass the intialization\n"); */
	
	for(int i = 0;i < B;i++)
	{
	
		for(int j = 0;j < M;j++)
		{
			ptr[i][j] = (int *)malloc((B*M)*sizeof(int));
		}
	}

	for(int k = 0;k < B;k++)
	{
		for(int i = 0;i < M;i++)
		{
			if(ptr[i])
			{
				for(int j = 0;j < N;j++)
				{
					ptr[k][i][j] = value;
		// Test ------			printf("3dintarr_ptr[%d][%d][%d] = %d\n",k,i,j,ptr[k][i][j]);
				}
			}	
		}
	}

/* Test ----	printf("Get pass giving value\n"); */

	for(int i = 0;i<B;i++)
	{
		for(int j = 0;j<M;j++)
		{
			free(ptr[i][j]);
		}
	}
	
}
void alloate_doub(double value)
{
	double *ptr = NULL;
	ptr = malloc(sizeof(double));

	if(ptr)
	{
		*ptr = value;
/* Test ---		printf("doub_ptr = %f\n", *ptr); */
	}

	free(ptr);

}
void alloate_doubarr(double value,int N)
{

	double *ptr = calloc(N, sizeof(double));

	if(ptr)
	{
		for(int i = 0;i < N;i++)
		{
			ptr[i] = value;
	/*	Test ---	printf("doubarr_ptr[%d] = %f\n",i,ptr[i]); */
		}
	}

	free(ptr);

}
void alloate_2ddoubarr(double value,int M,int N)
{

	/* Malloc intalize a pointer so you have to set
	the pointer in your array */
	double *ptr[M];
	
	// Intializing ptr arr
	for(int i = 0;i < M;i++)
	{
		ptr[i] = NULL;
	}
	
	for(int i = 0;i < M;i++)
	{
		ptr[i] = (double *)malloc(M*sizeof(double));
	}

	for(int i = 0;i < M;i++)
	{
		if(ptr[i])
		{
			for(int j = 0;j < N;j++)
			{
				ptr[i][j] = value;
	// Test----			printf("2ddoubarr_ptr[%d][%d] = %f\n",i,j,ptr[i][j]);
			}
		}	
	}

	for(int i = 0;i<M;i++)
	{
		free(ptr[i]);
	}

}

void alloate_char(char value)
{

	double *ptr = NULL;
	ptr = malloc(sizeof(double));

	if(ptr)
	{
		*ptr = value;
/* Test ---		printf("char_ptr = %c\n", *ptr); */
	}

	free(ptr);

}
void alloate_chararr(char value,int N)
{

	char *ptr = calloc(N, sizeof(char));

	if(ptr)
	{
		for(int i = 0;i < N;i++)
		{
			ptr[i] = value;
	/*	Test ---	printf("chararr_ptr[%d] = %c\n",i,ptr[i]); */
		}
	}

	free(ptr);

}
void alloate_2dchararr(char value,int M,int N)
{


	/* Malloc intalize a pointer so you have to set
	the pointer in your array */
	char *ptr[M];
	
	// Intializing ptr arr
	for(int i = 0;i < M;i++)
	{
		ptr[i] = NULL;
	}
	
	for(int i = 0;i < M;i++)
	{
		ptr[i] = (char *)malloc(M*sizeof(char));
	}

	for(int i = 0;i < M;i++)
	{
		if(ptr[i])
		{
			for(int j = 0;j < N;j++)
			{
				ptr[i][j] = value;
	// Test----			printf("2dchararr_ptr[%d][%d] = %c\n",i,j,ptr[i][j]);
			}
		}	
	}

	for(int i = 0;i<M;i++)
	{
		free(ptr[i]);
	}

}

int main()
{
	int N = 0;
	int M = 0;
	int B = 0;

	// Getting input for B, M, N for array size
	printf("Enter the number of columns...\n");
	scanf("%d",&N);

	printf("Enter the number of rows...\n");
	scanf("%d",&M);

	printf("Enter how far the rows & columns push out...\n");
	scanf("%d",&B);

	// First parameter is the value (1) and next will deal with the array sizes
	alloate_int(1);
	alloate_intarr(1,N);
	alloate_2dintarr(1,M,N);
	alloate_3dintarr(1,B,M,N);
	////////
	alloate_doub(1.6);
	alloate_doubarr(1,N);
	alloate_2ddoubarr(1,M,N);
	///////
	alloate_char('1');
	alloate_chararr('1',N);
	alloate_2dchararr('1',M,N);

	return 0;
}
