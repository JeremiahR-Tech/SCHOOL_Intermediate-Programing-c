#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include"Problem1.h"

int main(int argc, char *argv[])
{
            int BUFF_SIZE = 1028;
            char buffer[BUFF_SIZE];
            
            if(argc != 2)
            {
                printf("USAGE: ./a.out FILENAME VALUE\n");
		return 1;
            }

            FILE *fp = fopen(argv[1],"r");
            
            if(fp == NULL)
            {
                printf("FILE could not be opened\n");
                return 9;

            }
        vehicle *car = calloc(1, sizeof(vehicle));

        while(1){

	printf("Beginning of loop!\n");
	long begin = 0;

		fread(&car->size,sizeof(long),1,fp);

		if(feof(fp))
		{
			break;
		}
		begin = ftell(fp);
		printf("Size: %ld\n",car->size);
		fread(&car->year,sizeof(int),1,fp);
		printf("Year: %d\n",car->year);
	/* Now that we've gotten the size and the year
	we can now think about how getting string length*/
		int length = 0;
		long start = ftell(fp);
		while(fgetc(fp))
		{
			length++;
		}
		printf("Length(Make): %d\n",length);
		car->make = calloc(length+1,sizeof(char));
		fseek(fp,start,SEEK_SET);
		fread(car->make,sizeof(char),length+1,fp);
		printf("Make: %s\n",car->make);

		// Model
		length = 0;
		start = ftell(fp);
		while(fgetc(fp))
		{
			length++;
		}
		printf("Length(Model): %d\n",length);
		car->model = calloc(length+1,sizeof(char));
		fseek(fp,start,SEEK_SET);
		fread(car->model,sizeof(char),length+1,fp);
		printf("Model: %s\n",car->model);

		// Color
		length = 0;
		start = ftell(fp);
		while(fgetc(fp))
		{
			length++;
		}
		printf("Length(color): %d\n",length);
		car->color = calloc(length+1,sizeof(char));
		fseek(fp,start,SEEK_SET);
		fread(car->color,sizeof(char),length+1,fp);
		printf("Color: %s\n",car->color);

		// License_plate
		length = 0;
		start = ftell(fp);
		length = car->size - (start - begin);
		printf("Length(Lisence): %d\n",length);
		car->license_plate = calloc(length,sizeof(char));
		fseek(fp,start,SEEK_SET);
		fread(car->license_plate,sizeof(char),length,fp);
		printf("License: %s\n",car->license_plate);



        }

	return 0;

}
