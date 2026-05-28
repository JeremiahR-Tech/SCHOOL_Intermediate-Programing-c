#include "src/utils/hash_map_utils.h"
#include "src/vehicle.h"

#ifdef DEBUG
#define printd(s) printf("[DEBUG] %s\n", s);
#else
#define printd(s)
#endif

void print_array(dynamic_array_t *array) {
    for (int i = 0; i < array->size - 1; i++) {
        hash_element_t *elem = array->data[i];
        printf("%s, ", ((vehicle_t *)elem->value)->license_plate);
    }
    hash_element_t *elem = array->data[array->size - 1];
    printf("%s\n", ((vehicle_t *)elem->value)->license_plate);
}

void print_map(dynamic_array_t **map, int array_size) {
    for (int i = 0; i < array_size; i++) {
        printf("map[%d] = ", i);
        if (map[i] == NULL) {
            printf("EMPTY\n");
        } else {
            print_array(map[i]);
        }
    }
}

void trim(char *str)
{
	int l = strlen(str);
	if(str[l-1] == '\n')
	{
		str[l-1] = 0;
	}
}


vehicle_t *parse_csv(char *csv_line)
{
	char *token = strtok(csv_line, ",");
	int property = 0;
	int num_tokens = 0;
	vehicle_t *v = calloc(1,sizeof(vehicle_t));

	while(token != NULL)
	{
		switch(property)
		{
			case 0:
			{
				v->year = atoi(token);
				break;
			}
			case 1:
			{
				v->make = calloc((strlen(token)+1),sizeof(char));
				strcpy(v->make,token);
				break;
			}
			case 2:
			{
				v->model = calloc((strlen(token)+1),sizeof(char));
				strcpy(v->model,token);
				break;
			}
			case 3:
			{
				v->color = calloc((strlen(token)+1),sizeof(char));
				strcpy(v->color,token);
				break;
			}
			case 4:
			{
				v->license_plate = calloc((strlen(token)+1),sizeof(char));
				strcpy(v->license_plate,token);
				break;
			}
			default:
				break;
		}
		num_tokens++;
		property++;
		token = strtok(NULL, ",");
	}

	if(num_tokens != 5)
	{
		free(v);
		v = NULL;
	}

	return v;
}


int main() {
    	char buffer[BUF_SIZE] = { 0 };
    	hash_map_t *map = calloc(1, sizeof(hash_map_t));
    	init_map(map, 4);
	int choice = 0;
	int choice_add = 0;
	char *filename = NULL;


	do
	{
		// Get user data for the choice
		printf("1. Add Vehicle\n");
		printf("2. Import File\n");
		printf("3. Vehicle Lookup\n");
		printf("4. Print Map\n");
		printf("5. Quit\n");
		printf(" > ");
		scanf("%d",&choice);
		while(!(getchar() == '\n')); // Clearing buffer

		sprintf(buffer,"Choice: %d",choice);
		printd(buffer);

		switch(choice)
		{
			case(1): // Add Vehicle
			{

				do
				{
       					printf("Enter a key: ");
        				fgets(buffer, BUF_SIZE, stdin);
        				trim(buffer);

	        			hash_element_t *elem = search(map, buffer);

	        			if (elem != NULL)
					{
            					printf("%s found!\n", buffer);
            					print_vehicle(elem->value);
						break;
        				}

        				// Copy the data to a hash_element_t
        				elem = calloc(1, sizeof(hash_element_t));
        				elem->key = malloc(sizeof(char) * (strlen(buffer) + 1));
        				strcpy(elem->key, buffer);

        				// Get value from the user
	        			vehicle_t *v = calloc(1, sizeof(vehicle_t));

        				v->license_plate = calloc(strlen(elem->key) + 1, sizeof(char));
      				  	strcpy(v->license_plate, elem->key);

      				  	input_vehicle(v);

     			   		elem->value = v;

 			   	    	// Add element to the map
  			      		insert(map, elem);

					// Add Vehicle Menu
					printf("1. Continue\n");
					printf("2. Go Back\n");
					printf(" > ");
					scanf("%d",&choice_add);
					while(!(getchar() == '\n'));
					sprintf(buffer,"Choice(add): %d",choice);
					printd(buffer);
		   		} while(!(choice_add == 2));

				break;
			}
			case(2): // Import File
			{
				// Getting filename
				printf("Enter filename(Must be CSV): ");
				fgets(buffer,BUF_SIZE,stdin);
				trim(buffer);

				// intializing filename
				filename = realloc(filename,(strlen(buffer)+1) * sizeof(char));
				strcpy(filename,buffer);

				FILE *fp = fopen(filename,"r");
				if(!fp)
				{
					printf("Cannot open file. Returning to menu...\n");
					printf("\n");
					break;
				}

				// This is intended to be an array of vehicles holding all the csv file data
				dynamic_array_t *betty = calloc(1,sizeof(dynamic_array_t));
				betty->data = calloc(1,sizeof(void *));
				sprintf(buffer,"MAIN_MENU::IMPORT_FILE|Before setting array->data to vehicle ptr");
				printd(buffer);

				while(fgets(buffer,BUF_SIZE,fp))
				{
					trim(buffer);
					vehicle_t *t = parse_csv(buffer);

					if(t != NULL)
					{
						betty->data = realloc(betty->data,sizeof(void *) * (betty->size + 1));
						betty->data[betty->size] = t;
						betty->size++;
						sprintf(buffer,"I'm on loop %d\n",betty->size);
						printd(buffer);
					}
				}

				// Now its time to put all of these into a hashmap!
				for(int i = 0; i < betty->size;i++)
				{
					vehicle_t *t = betty->data[i];
					strcpy(buffer,t->license_plate);
					trim(buffer);
					hash_element_t *elem = search(map, buffer);

	        			if (elem != NULL)
					{
            					printf("%s found!\n", buffer);
            					print_vehicle(elem->value);
        				}
					else
					{
        					// Copy the data to a hash_element_t
        					elem = calloc(1, sizeof(hash_element_t));
        					elem->key = realloc(elem->key,sizeof(char) * (strlen(buffer) + 1));
        					strcpy(elem->key, buffer);

						elem->value = t;

 				   	    	// Add element to the map
  				      		insert(map, elem);
					}
				}
				// Closing up loose-ends
				printf("File succesfully imported!\n");

				fclose(fp);
				free(filename);
				for(int i = 0;i < betty->size;i++)
				{
					sprintf(buffer,"Freeing betty->data[%d]\n",i);
					printd(buffer);
					free(betty->data[i]);
				}
				free(betty);

				break;
			}
			case(3): // Vehicle Lookup
			{
				printf("Enter a key: ");
        			fgets(buffer, BUF_SIZE, stdin);
        			trim(buffer);

	        		hash_element_t *elem = search(map, buffer);

	        		if(elem != NULL)
				{
					int index = compute_index(buffer,map->map_size);

            				printf("%s found!\n", buffer);
    					for (int i = 0; i < map->primary[index]->size - 1; i++)
					{
        					hash_element_t *elem = map->primary[index]->data[i];
						vehicle_t *v = ((vehicle_t *)elem->value);
						print_vehicle(v);

    					}
					hash_element_t *elem = map->primary[index]->data[map->primary[index]->size - 1];
					vehicle_t *v = ((vehicle_t *)elem->value);
					print_vehicle(v);


        			}
				else
				{
					printf("ALERT! There is no such lisence plate.\n");
				}

				break;
			}
			case(4): // Print Map
			{
      			  	print_map(map->primary, map->map_size);
				break;
			}
			case(5): // Quit
			{
				break;
			}
			default:
			{
				printf("ERROR! Invalid option. Please choose again.\n");
				break;
			}
		}
	} while(!(choice == 5));

	// End of Program
    	return 0;
}

