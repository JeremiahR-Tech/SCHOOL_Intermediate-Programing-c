#include "problem1.h"

/*Jeremiah Richard
CSE1320-001
Professor Dillhoff
11/20/2021 */

void trim(char *str)
{
	int l = strlen(str);
	if(str[l-1] == '\n')
	{
		str[l-1] = 0;
	}
}

vehicle_t parse_csv(char *csv_line)
{
        char *token = strtok(csv_line, ",");
        int property = 0;
        int num_tokens = 0;
        vehicle_t v = { 0 };

        while(token != NULL)
        {
                switch(property)
                {
                        case 0:
                        {
                                v.year = atoi(token);
                                break;
                        }
                        case 1:
                        {
                                v.make = calloc((strlen(token)+1),sizeof(char));
                                strcpy(v.make,token);
                                break;
                        }
                        case 2:
                        {
                                v.model = calloc((strlen(token)+1),sizeof(char));
                                strcpy(v.model,token);
                                break;
                        }
                        case 3:
                        {
                                v.color = calloc((strlen(token)+1),sizeof(char));
                                strcpy(v.color,token);
                                break;
                        }
                        case 4:
                        {
                                v.license = calloc((strlen(token)+1),sizeof(char));
                                strcpy(v.license,token);
                                break;
                        }
			default:
                               break;
                }
                num_tokens++;
                property++;
                token = strtok(NULL, ",");
        }

        return v;


}

void upload_file(FILE *file, BTNode **root)
{
/*	int loop_num = 0;
	while(1)
	{
		if(feof(file))
		{
			break;
		}
		char buffer[BUF_SIZE] = { 0 };
		fgets(buffer,BUF_SIZE,file);
		vehicle_t v = parse_csv(buffer);
		insert(root,v);

		loop_num++;
		printd("Loops: %d\n",loop_num);
	}*/
}

int main()
{
	int choice = 0;
	BTNode *root = NULL;
	do
	{
		printf("1. Upload CSV\n");
		printf("2. Vehicle List\n");
		printf("3. Vehicle Lookup\n");
		printf("4. Quit\n");
		printf(" > ");
		scanf("%d",&choice);
		printd("Choice: %d\n",choice);
		while(!(getchar() == '\n'));

		switch(choice)
		{
			case(1): // Upload CSV
			{
				printf("Enter filename(Must be CSV): ");
				char buffer[BUF_SIZE] = { 0 };
				fgets(buffer,BUF_SIZE,stdin);
				printd("Buffer: %s\n",buffer);
				trim(buffer);

				char *filename = realloc(filename,(strlen(buffer)+1) * sizeof(char));
				strcpy(filename,buffer);
				printd("Filename: %s\n",filename);

				FILE *file = fopen(filename,"r");
				if(!file)
				{
					printf("Could not open the file.\n"); 
					break;
				}
/*
				fgets(buffer,BUF_SIZE,file);
				vehicle_t v = parse_csv(buffer);
				printd("1st V parse of %s \n",buffer);
				print_vehicles(v);
				root = add_btnode(v);

				printd("Made it pass intializing root. Choice: %d\n", choice);
*/
//				upload_file(file,&root);

				int test_loop_num = 0;
				while(1)
				{
					if(feof(file))
					{
						break;
					}
					char buffer[BUF_SIZE] = { 0 };
					fgets(buffer,BUF_SIZE,file);
					vehicle_t v = parse_csv(buffer);
					insert(&root,v);

					test_loop_num++;
					printd("Loops: %d\n",test_loop_num);
				}



				fclose(file);
				free(filename);
				break;
			}
			case(2): // Vehicle List
			{
				if(root != NULL)
				{
					dfs(root,PREORDER);
					printf("\n");
					printd("Got pass traverse! Choice: %d\n",choice);
				}
				else
				{
					printf("[ERROR] No vehicle data!\n");
				}
				break;
			}
			case(3): // Vehicle Lookup
			{
				int search_yr = 0;
				printf("Year of the vehicle: \n");
				printf(" > ");
				scanf("%d",&search_yr);
				while(getchar() != '\n');

				BTNode *car = search(root,search_yr);
				print_vehicles(car->data);

				break;
			}
			case(4): // Quit
			{
				// Don't forget to free the strings of each node vehicle
				release_tree(root);
				break;
			}
			default:
			{
				printf("Invaild choice!\n");
				break;
			}
		}
	}while(!(choice == 4));

	return 0;
}
