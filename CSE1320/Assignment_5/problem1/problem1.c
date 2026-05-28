/*Jeremiah Richard
CSE13200.001
Professor Dillhoff
10/15/2021
Problem1.c */

#include "problem1.h"
#define YEAR_SIZE 4
#define BUF_SIZE 1024

void print_vehicles(Vehicle car)
{
/*	printf("Size: %ld\n",car.size); */
	printf("Year: %d\n",car.year);
	printf("Make: %s\n",car.make);
	printf("Model: %s\n",car.model);
	printf("Color: %s\n",car.color);
	printf("Lisence Plate: %s\n",car.lisence_plate);
}

// returns the count of parameter from search term)
int shift_through(char *str,char *search_term)
{
	int count = 0;

	for(int j = 0;j < strlen(str);j++)
	{
		count = 0;
		int k = 0;
		if(search_term[k] == str[j])
		{
			while(search_term[k] == str[j+k])
			{
				if(str[j+k] == '\0')
				{
					break;
				}
				count++;
				k++;
			}
		}
		if(count == strlen(search_term))
		{
			break;
		}
	}


	return count;
}

// This will actually search for the term we're looking for
void find_term(char *search_term, Vehicle *car, int index)
{
	/* I need to convert number that is a number into string
	except size*/
	char year_string[YEAR_SIZE] = { 0 };

/*	printf("Search term length: %ld\n",strlen(search_term)); TEST --

	printf("---------------------------------------------------\n");  */

	/*If it finds a match in search it prints the whole struct */

	// i controls which car, j controls index for members string, k controls index for search term
	for(int i = 0; i < index;i++)
	{
		sprintf(year_string,"%d",car[i].year);
/* TEST ---		printf("Year[%d]: %s\n",i,year_string); */
		/*I can access the car, now I need to got through
		each string and see if it matches the search term
		by each letter exactly.*/

		// For the year...
		int count = 0;

	/*	printf("Count: %d\n",count); TEST --- */

		// ---  YEAR ---
		count = shift_through(year_string,search_term);

		// Checking if count is the same as the strlen of the search_term to print the item
		if(count == strlen(search_term))
		{
			print_vehicles(car[i]);
			continue;
		}
		else
		{
			count = 0; // Need to reset count ot zero for each string
		}

		// --- MAKE ---
		count = shift_through(car[i].make,search_term);

		// Checking if count is the same as the strlen of the search_term to print the item
		if(count == strlen(search_term))
		{
			print_vehicles(car[i]);
			continue;
		}
		else
		{
			count = 0; // Need to reset count ot zero for each string
		}

		// --- MODEL ---
		count = shift_through(car[i].model,search_term);

		// Checking if count is the same as the strlen of the search_term to print the item
		if(count == strlen(search_term))
		{
			print_vehicles(car[i]);
			continue;
		}
		else
		{
			count = 0; // Need to reset count ot zero for each string
		}

		// --- COLOR ---
		count = shift_through(car[i].color,search_term);

		// Checking if count is the same as the strlen of the search_term to print the item
		if(count == strlen(search_term))
		{
			print_vehicles(car[i]);
			continue;
		}
		else
		{
			count = 0; // Need to reset count ot zero for each string
		}

		// --- Lisence_PLATE ---
		count = shift_through(car[i].lisence_plate,search_term);

		// Checking if count is the same as the strlen of the search_term to print the item
		if(count == strlen(search_term))
		{
			print_vehicles(car[i]);
			continue;
		}
		else
		{
			count = 0; // Need to reset count ot zero for each string
		}



	}

	return;
}


Vehicle read_binaryfile(FILE *fp)
{

	//arr_size = index
	Vehicle car = { 0 };

	/*printf("Got in read_binary\n"); --- TE0ST --*/

	long begin = 0;
/*TEST ---	printf("Got pass reallocation..\n"); */
	// Reading size of struct without long
	fread(&car.size,sizeof(long),1,fp);

	if(feof(fp))
	{
		return car;
	}

	// Actually beginning
	begin = ftell(fp);

	// Read year...
	fread(&car.year,sizeof(int),1,fp);

	// Read make(first string)...
	long string_start = ftell(fp);
	while(fgetc(fp));
	long string_end = ftell(fp);
	fseek(fp,string_start,SEEK_SET);
	car.make = calloc(string_end - string_start,sizeof(char));
	fread(car.make, sizeof(char),string_end - string_start,fp);


	// Read model(second string)...
	string_start = ftell(fp);
	while(fgetc(fp));
	string_end = ftell(fp);
	fseek(fp,string_start,SEEK_SET);
	car.model = calloc(string_end - string_start,sizeof(char));
	fread(car.model, sizeof(char),string_end - string_start,fp);


	// Read color(third string)...
	string_start = ftell(fp);
	while(fgetc(fp));
	string_end = ftell(fp);
	fseek(fp,string_start,SEEK_SET);
	car.color = calloc(string_end - string_start,sizeof(char));
	fread(car.color, sizeof(char),string_end - string_start,fp);

	// Reading Lisence Plate
	string_start = ftell(fp);
	int string_size = car.size - (string_start - begin);
	car.lisence_plate = calloc(string_size + 1,sizeof(char));
	fread(car.lisence_plate,sizeof(char),string_size,fp);

	return car;
}

int main(int argc, char** argv)
{

	if(!(argc == 3))
	{
		printf("ERROR! USAGE: ./a.out FILENAME search_term\n");
		return 1;
	}

	// Intializing and Allocating
	Vehicle *car = calloc(1,sizeof(Vehicle));
	int term_size = strlen(argv[2]);
	int filename_size = strlen(argv[1]);
	char *filename = calloc((filename_size+1),sizeof(char));
	char *search_term = calloc((term_size+1),sizeof(char));

/* TEST -----	printf("Pass allocation..\n"); */

	strcpy(filename,argv[1]);
	strcpy(search_term,argv[2]);

/* TEST -----	printf("Pass intialization..\n"); */

	// Opening file
	FILE *bin_file = fopen(filename, "rb");
	if(!bin_file)
	{
		printf("Cannot open the file.\n");
		return 1;
	}

/* --- TEST ---*/
	printf("search_term: %s\n",search_term);
	printf(" \n");
// Doing heart of the program
	// This should get all of our data from the file so we can use it in our search function
	int index = 0;
	while(1)
	{
		Vehicle v = read_binaryfile(bin_file);
		if(v.make == NULL)
		{
			break;
		}
		car = realloc(car,sizeof(Vehicle) * (index+1));
		car[index] = v;
/* TEST ----		print_vehicles(car[index]); */
		index++;
/*		printf("Index outside read(after add): %d\n",index); */
	}

	find_term(search_term,car,index);

	// Releasing all data and closing file
	fclose(bin_file);
	free(search_term);
	free(filename);
	for(int i = 0;i < (index-1);i++)
	{
		free(car[i].make);
		free(car[i].model);
		free(car[i].color);
		free(car[i].lisence_plate);
	}

	free(car);

	return 0;
}
