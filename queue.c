/*A call center phone system has to hold the phone calls from customers and provide service based on the arrival time of the calls. Write a C program to simulate this system using queue data structure. Program should have options to add and remove the phone calls in appropriate order for their service.*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct{
    int* q;
    int f;
    int r;
    int max;
} QUEUE;

QUEUE* create(int max) {
    QUEUE* queue = (QUEUE*)malloc(sizeof(QUEUE));
    queue->f = 0;
    queue->r = -1;
    queue->max = max;
    queue->q = (int*)malloc(queue->max*sizeof(int));
    return queue;
}

bool full(QUEUE* queue){
    return ((queue->r+1) == queue->max);
}

bool empty(QUEUE* queue){
    return (queue->f > queue->r);
}

void enqueue(QUEUE* queue, int item){
    if(full(queue)){
        printf("Queue is full.\n");
        return;
    }
    queue->q[++queue->r] = item;
}

int dequeue(QUEUE* queue) {
    if(empty(queue)) {
        printf("Queue is empty.\n");
        return -1;
    }
    return queue->q[queue->f++];
}

void liberate(QUEUE* queue){
    free(queue->q);
    free(queue);
}

void display(QUEUE* queue) {
    if(empty(queue)){
        printf("Queue is full.\n");
        return;
    }
    for(int i = queue->f; i <= queue->r; i++){
        printf(" %d", queue->q[i]);
    }
    printf("\n");
}

int main() {
    int choice, item, size;
    printf("Enter the size of the queue: ");
    scanf("%d", &size);

    QUEUE* queue = create(size);

    do {
        printf("\nQueue Operations\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the item to enqueue: ");
                scanf("%d", &item);
                enqueue(queue, item);
                break;
            case 2:
                item = dequeue(queue);
                if (item != -1)
                    printf("Dequeued item: %d\n", item);
                break;
            case 3:
                printf("Queue elements: ");
                display(queue);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);

    liberate(queue);
    return 0;
}