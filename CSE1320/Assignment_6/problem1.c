/*Jeremiah Richard
CSE1320
Professor Dillhoff
Assignment 6
10/29/2021 */

#include "problem1.h"

#define BUFF_SIZE 1024

void trim(char *buffer)
{
	int i = strlen(buffer);
	if(buffer[i-1] == '\n')
	{
		buffer[i-1] = 0;
	}
}

void print_vehicle(vehicle_t car)
{
	printf("%d %s %s %s %s\n",car.year,car.make,car.model,car.color,car.license);
}

vehicle_t getcarinfo()
{
	vehicle_t car = { 0 };
	char buffer[BUFF_SIZE] = { 0 };

	printf("What is the year of the vehicle? ");
	scanf("%d",&car.year);
	while(getchar() != '\n');

	// Getting strings - make
	printf("What is the make of the vehicle? ");
	fgets(buffer,BUFF_SIZE,stdin);
	trim(buffer);
	car.make = calloc((strlen(buffer)+1),sizeof(char)); 
	strcpy(car.make,buffer);

 	// Getting strings - model
	printf("What is the model of the vehicle? ");
	fgets(buffer,BUFF_SIZE,stdin);
	trim(buffer);
	car.model = calloc((strlen(buffer)+1),sizeof(char)); 
	strcpy(car.model,buffer);

 	// Getting strings - color
	printf("What is the color of the vehicle? ");
	fgets(buffer,BUFF_SIZE,stdin);
	trim(buffer);
	car.color = calloc((strlen(buffer)+1),sizeof(char)); 
	strcpy(car.color,buffer);

 	// Getting strings - lisence
	printf("What is the license of the vehicle? ");
	fgets(buffer,BUFF_SIZE,stdin);
	trim(buffer);
	car.license = calloc((strlen(buffer)+1),sizeof(char)); 
	strcpy(car.license,buffer);

/* TEST -----	printf("In function: \n");
	print_vehicle(car);
	printf("-----------------\n"); */

/*	vehicle_t temp = car;
	free(temp.make);
	free(temp.model);
	free(temp.color);
	free(temp.license);*/

// Test ---	print_vehicle(car);

	return car;
}

dynamic_array remove_car(dynamic_array buddy)
{
	if(!(buddy.size == 0))
	{
		for(int i = 0; i < buddy.size-1;i++)
		{
			buddy.data[i] = buddy.data[i+1];
		}
		buddy.size--;
		buddy.data = realloc(buddy.data,buddy.size * (sizeof(vehicle_t)));
		return buddy;
	}
	else
	{
		printf("No cars to repair.\n");
		return buddy;
	}
}

int main()
{
	int choice = 0;
	int repair_choice = 0;
	dynamic_array car_list = { 0 };

	do
	{
		printf(" 1. Add Vehicle\n");
		printf(" 2. View Next Vehicle\n");
		printf(" 3. View Current Queue\n");
		printf(" 4. Quit\n");
		printf(" > ");
		scanf("%d",&choice);
		printf("Choice: %d\n",choice);

		switch(choice)
		{
			case(1):
			{
				car_list.data = realloc(car_list.data,(car_list.size+1) * (sizeof(vehicle_t)));
				car_list.size++;
				car_list.data[(car_list.size)-1] = getcarinfo();
				printf("Vehicle stored: \n");
				print_vehicle(car_list.data[(car_list.size)-1]);
				printf("\n");
				break;
			}
			case(2):
			{
				printf(" Next up: \n");
				if(car_list.size == 0)
				{
					printf("There are no cars in queue.\n");
					break;
				}
				else
				{
					print_vehicle(car_list.data[0]);
					printf(" 1. Start Repair\n");
					printf(" 2. Go back\n");
					printf(" > ");
					scanf("%d",&repair_choice);
					printf("Choice: %d\n",repair_choice);
				}

				switch(repair_choice)
				{
					case(1):
					{
						car_list = remove_car(car_list);
						break;
					}
					case(2):
					{
						break;
					}
					default:
					{
						printf("Invalid option...\n");
						break;
					}
				}
				break;
			}
			case(3):
			{
				for(int i = 0; i < car_list.size;i++)
				{
					printf("%d. ",i+1);
					print_vehicle(car_list.data[i]);
				}
				printf("\n");
				break;
			}
			case(4):
			{
				for(int i = 0; i < car_list.size;i++)
				{
					free(car_list.data[i].make);
					free(car_list.data[i].model);
					free(car_list.data[i].color);
					free(car_list.data[i].license);
				}
				free(car_list.data);
 				break;
			}
			default:
				printf("Invalid Option...\n");
		}
	} while(!(choice == 4));

	return 0;
}
