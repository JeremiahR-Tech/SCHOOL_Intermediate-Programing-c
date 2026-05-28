#include "problem2.h"

/*Jeremiah Richard
CSE1320.001
Professor Dillhoff
10/19/21
Assignment5_Problem2 */

#define BUFFER_SIZE 1024

void print_vehicle(Vehicle v)
{
	printf("Year: %d\n",v.year);
	printf("Make: %s\n",v.make);
	printf("Model: %s\n",v.model);
	printf("Color: %s\n",v.color);
	printf("Lisence_plate: %s\n",v.lisence_plate);
}

void print_nodes(Node *n)
{
	if(n != NULL)
	{
//		printf("Node ptr(address): %p\n",&n);
//		printf("Node (address): %p\n",n);
		Vehicle val = n->data;
		print_vehicle(val);
		print_nodes(n->next);
	}
}

void trim(char *str)
{
	int l = strlen(str);
	if ((str[l-1]) == '\n')
	{
		str[l-1] = 0;
	}

}

Vehicle parse_csv(char *csv_line)
{
	char *token = strtok(csv_line, ",");
	int property = 0;
	Vehicle v = { 0 };

//	printf("I was able to get the first token!\n");

	while(token != NULL)
	{
		switch(property)
		{
			case 0:
			{
				v.year = atoi(token);
//				printf("I had got year!\n"); 
				break;
			}
			case 1:
			{
// TEST ----				printf("Right before strcpy call...token: %s\n",token);
				v.make = calloc((strlen(token)+1),sizeof(char));
//				printf("Made it pass allocation of make!\n");
				strcpy(v.make,token);
//				printf("I had got make!\n"); 
				break;
			}
			case 2:
			{
				v.model = calloc((strlen(token)+1),sizeof(char));
				strcpy(v.model,token);
//				printf("I had got model!\n"); 
				break;
			}
			case 3:
			{
				v.color = calloc((strlen(token)+1),sizeof(char));
				strcpy(v.color,token);
//				printf("I had got color!\n");
				break;
			}
			case 4:
			{
				v.lisence_plate = calloc((strlen(token)+1),sizeof(char));
				strcpy(v.lisence_plate,token);
//				printf("I had got the plate!\n");
				break;
			}
			default:
				break;
		}
		property++;
//		printf("Right before next token!\n");
		token = strtok(NULL, ",");
	}

// TEST ----	printf("Right before the return!\n");

	return v;
}

Vehicle read_csv(FILE *csv_file)
{
	Vehicle v = { 0 };
	char buffer[BUFFER_SIZE] = { 0 };
	fgets(buffer, BUFFER_SIZE,csv_file);

	if(feof(csv_file))
	{
		return v;
	}

	trim(buffer);

	v = parse_csv(buffer);
	return v;
}

void free_linklist(Node *n)
{
	// I will use this to find double frees is a problem!
//	int i = 0;
	if(n != NULL)
	{
		Vehicle val = n->data;
		free(val.make);
		free(val.model);
		free(val.color);
		free(val.lisence_plate);
	//	printf("[%d]\n",++i);
		free_linklist(n->next);
	}
}

Node *create_node(Vehicle v)
{
	Node *new_node = calloc(1,sizeof(Node));
	new_node->data = v;

	return new_node;
}

// This function will grab all the makes of each node and put it in a string list
void grab_makes(Node *n, int ll_size,char make_list[][BUFFER_SIZE])
{

	int j = 0;
	while(n != NULL)
	{
		Vehicle temp = n->data;
		strcpy(make_list[j],temp.make);
		j++;
		n = n->next;
	}
	j = 0;

/* TEST ----	for(int i = 0;i < ll_size;i++)
	{
		printf("Make[%d]: %s\n",i,make_list[i]);
	} */

}

void print_choice(char *make_output, Node *n)
{
	Vehicle test = { 0 };
	while(n != NULL)
	{
		test = n->data;
		if(!(strcmp(make_output,test.make)))
		{
			print_vehicle(test);
		}
		n = n->next;
	}
}

int main(int argc,char **argv)
{
	if(!(argc == 2))
	{
		printf("ERROR! ./a.out FILENAME\n");
		return 1;
	}

	// Intializing values
	int filename_size = strlen(argv[1]);
	char *filename = calloc(1,sizeof(char) * filename_size);
	strcpy(filename,argv[1]);

// TEST---	printf("Filename: %s\n",filename);

	FILE *csv_file = fopen(filename,"r");
	if(!csv_file)
	{
		printf("Cannot open file.\n");
		return 1;
	}

	int ll_size = 0;

	// Creating nodes for vehicle data
	Node *head = create_node(read_csv(csv_file));
	Node *tail = head;

	while(1)
	{
		Node *new_node = create_node(read_csv(csv_file));
		Vehicle car = new_node->data;
		if(car.make == NULL)
		{
			break;
		} 
		tail->next = new_node;
		tail = tail->next;
		ll_size++;
	}
	ll_size++;

	char make_list[ll_size][BUFFER_SIZE];
	grab_makes(head,ll_size,make_list);

	printf("----------------------------\n");
	printf("\n");

/* TEST ---	for(int i = 0;i < ll_size;i++)
	{
		printf("[%d]: %s\n",i,make_list[i]);
	} */


	// Making a key to access each make...
	int make_key[20] = { 0 };
	int index = 0;

	while((make_list[index][0]))
	{
		if(!(strcmp(make_list[index],make_list[index+1])))
		{
			make_key[index] = index+1;
		}
		index++;
	}

/*	for(int i = 0;i < ll_size;i++)
	{
		printf("Key[%d] = %d\n",i,make_key[i]);
	} */

	int count = 0; // Using for home many makes there is. 
	for(int i = 0;i < ll_size;i++)
	{
		if(make_key[i])
		{
			count++;
		}
	}

	index = 0;
	char make_output[count][BUFFER_SIZE];
	int k = 0;
	while(make_list[index][0])
	{
		int flag = strcmp(make_list[index],make_list[index+1]);
		if(flag)
		{
			strcpy(make_output[k],make_list[index]);
			k++;
		}
		index++;
	}
	k = 0;

	// Printing options for the user...
	printf("Press..\n");
	for(int i = 0;i < count;i++)
	{
		printf("%d. %s\n", i+1,make_output[i]);
	}
	printf("   > ");

	int choice = 0;
	scanf("%d",&choice);

	printf("Choice: %d\n",choice);
	printf("\n");

	print_choice(make_output[choice-1],head);

	

// TEST ----------------
//	printf("Count: %d\n",count);
//	print_nodes(head);
//-----------------------

	// Freeing data and linklist
	free_linklist(head);
	free(filename);
	fclose(csv_file);

	return 0;
}
