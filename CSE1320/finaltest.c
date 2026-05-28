#include <stdio.h>
#include <stdlib.h>



 typedef struct {
    int year;
    char *make;
    char *model;
    char *color;
    char *liscense;

} vehicle_t;

void enqueue(vehicle_t **queue, int *size, vehicle_t *data) {

     vehicle_t *v = calloc(10, sizeof(void *));
  v = calloc(1, sizeof(vehicle_t));
     v->make = calloc(2, sizeof(char));
    v->model = calloc(2,sizeof(char));
     v->color = calloc(2,sizeof(char));
    v->liscense = calloc(2,sizeof(char));
   

     
  printf("Year: ");
     scanf("%d",&v->year);
     printf("Make: ");
     scanf("%49s",v->make);
     printf("Model: ");
     scanf("%49s",v->model);
      printf("Color: ");
       scanf("%49s",v->color);
       printf("Liscense: ");
        scanf("%49s",v->liscense);

    *queue = realloc(*queue, (*size + 1) * sizeof(int));

    // Shift data to the right.
    for (int i = *size; i > 0; i--) {
        (*queue)[i] = (*queue)[i - 1];
    }

    (*queue)[0] = data;

    (*size)++;
    
     free(v);
}

int dequeue(vehicle_t **queue, int *size) {
    if (*size == 0) {
        printf("Nothing to dequeue!\n");
        return 0;
    }

    (*size)--;

    *queue = realloc(*queue, *size * sizeof(int));

    return (queue)[*size];
}

void print_queue(vehicle_t *queue, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d\n", queue[i]);
    }
}

int main() {
    vehicle_t *queue = NULL;
   int size = 0;
   vehicle_t data = {0};
 

    
    
        


    enqueue(&queue,&size,&data);
  

   // print_queue(queue, size);

 //   printf("Dequeuing...\n");

   // dequeue(&queue, &size);

 //   print_queue(queue, size);

    return 0;
}                                       
