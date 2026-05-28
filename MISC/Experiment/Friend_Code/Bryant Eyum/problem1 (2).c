#include "problem1.h"
#define BUFF_SIZE 1000

void print_menu() {
    printf("1. Add Vehicle\n");
    printf("2. View Next Vehicle\n");
    printf("3. View Current Queue\n");
    printf("4. Quit\n");
}

void print_submenu() {
    printf("1. Start Repair\n");
    printf("2. Go back\n");
}

void clear_buffer() {
    while (getchar() != '\n');  //Stops the function from looping forever when you enter a character value.//
}

void submenu() {
    int menu_choice = 0;

    while (menu_choice != 2) {
        print_submenu();
        printf("Enter a selection: ");
        scanf("%d", &menu_choice);
        clear_buffer();

        switch (menu_choice) {
            case 1:
                // Start repair
               break;
            case 2:
                // Go back
                return;
            default:
                printf("Invalid selection.\n");
                break;
        }
    }
}

void trim(char *str) {
    int l = strlen(str);
    if (str[l-1] == '\n') {
        str[l-1] = 0;
    }
}

void print_data(vehicle_t data) {
    printf("%d %s %s %s %s\n", data.year,data.make,data.model,data.color,data.license);
}

void print_car(vehicle_t car) {
    printf("Year: %d\n", car.year);
    printf("Make: %s\n", car.make);
    printf("Model: %s\n", car.model);
    printf("Color: %s\n", car.color);
    printf("License: %s\n", car.license);
}

void view_queue(vehicle_t *car,int size){
	for(int i = 0;i < size;i++)
	{
		printf("%d. ",i+1);
		print_data(car[i]);
	}

}


void getcarinfo(vehicle_t **car,int *size){

//    vehicle_t car = {0};
    char buffer[BUFF_SIZE] = {0};
    (*size)++;
    *car = realloc(*car, (sizeof(vehicle_t) * (*size)));

    printf("What is the year of the vehicle? ");
    scanf("%d", &(*car)[(*size)-1].year); //Segumentation fault here. 
    while(getchar() != '\n');

    // Getting strings - make
    printf("What is the make of this vehicle? ");
    fgets(buffer,BUFF_SIZE,stdin);
    trim(buffer);
    (*car)[(*size)-1].make = calloc((strlen(buffer)+1),sizeof(char));
    strcpy((*car)[(*size)-1].make, buffer);
  

    //Getting strings - model
     printf("What is the model of this vehicle? ");
    fgets(buffer,BUFF_SIZE,stdin);
    trim(buffer);
    (*car)[(*size)-1].model = calloc((strlen(buffer)+1),sizeof(char));
    strcpy((*car)[(*size)-1].model, buffer);

    //Getting strings - vehicle
    printf("What is the color of this vehicle? ");
    fgets(buffer,BUFF_SIZE,stdin);
    trim(buffer);
    ((*car)[(*size)-1].color) = calloc((strlen(buffer)+1),sizeof(char));
    strcpy(((*car)[(*size)-1].color), buffer);
     
     //Getting strings - license
    printf("What is the license of this vehicle? ");
    fgets(buffer,BUFF_SIZE,stdin);
    trim(buffer);
    ((*car)[(*size)-1].license) = calloc((strlen(buffer)+1),sizeof(char));
    strcpy((*car)[(*size)-1].license, buffer);

    
  /*  *car[0] = data;
    print_data(data); */
}

// 
/*dynamic_array_t getUserinfo(dyanmic_array_t cars)
{

	printf("What is the year? ")
	scanf("%d",cars.data[cars.size]->year);
	clear_buffer();

	printf

	return cars;
}*/

int main(){
 
     //To call a struct function, declare first, then set the identifier to the struct variable name function

  vehicle_t *car = NULL;
  int size = 0;

 //  vehicle_t data = {0}; // Just pass it like regular
   /* dynamic_array_t rocket = {0}; Not sure about these
    rocket.size = 0; */ //Not sure

// Cars vehicle_t *car, int size
// Trucks vehicle_t *car, int size
// SUV vehicle_t *car, int size

   int menu_choice = 0;

    while (menu_choice != 4) {
        print_menu();
        printf("Enter a selection: ");
        scanf("%d", &menu_choice);
        clear_buffer();

        switch (menu_choice) {
            case 1:
                // Add vehicle
                getcarinfo(&car,&size);  //getcarinfo(&car,data);
                break;
            case 2:
                // View next vehicle
                submenu();
                break;
            case 3:
                // View Current Queue
		view_queue(car,size);
		printf("\n");
                break;
            case 4:
                // Quit
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid selection.\n"); 
                break;
        }
    }

   return 0;
}

