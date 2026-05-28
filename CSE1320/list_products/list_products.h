#ifndef LIST_PRODUCTS_H
#define LIST_PRODUCTS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024
#define MAX_STR 128
#define CSEP_INT 1346720579
 
typedef struct
{
	int id;
	char name[MAX_STR];
	double price;
	int quantity;
} product;

void read_CSV(char *);
void read_binary(char *);
void print_product(product);
product parse_CSV_line(char *);
void trim(char *);
int check_CSEP(FILE *);




#endif
