/*A call center phone system has to hold the phone calls from customers and provide service based on the arrival time of the calls. Write a C program to simulate this system using queue data structure. Program should have options to add and remove the phone calls in appropriate order for their service.*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct {
    int* q;
    int f;
    int r;
    int max;
}QUEUE;

QUEUE* create(int max) {
    QUEUE* queue = (QUEUE*)malloc(sizeof(QUEUE));
    queue->max = max;
    queue->f = 0;
    queue->r = -1;
    queue->q = (int*)malloc((queue->max)*sizeof(int));
    return queue;
}

bool empty(QUEUE* queue){
    return (queue->f > queue->r);
}

bool full(QUEUE* queue) {
    return ((queue->max - 1) == queue->r);
}

void enqueue(QUEUE* queue, int item) {
    if(full(queue)) {
        printf("Queue is full.\n");
        exit(0);
    }
    queue->q[++queue->r] = item;
}

int dequeue(QUEUE* queue) {
    if(empty(queue)) {
        printf("Queue is empty.\n");
        exit(0);
    }
    return (queue->q[queue->f++]);
}

void display(QUEUE* queue){
    if(empty(queue)) {
        printf("Queue is empty.\n");
        exit(0);
    }
    for(int i = queue->f; i <= queue->r; i++){
        printf("%d ",queue->q[i]);
    }
    printf("\n");
}

void liberate(QUEUE* queue) {
    free(queue->q);
    free(queue);
}

int main() {
    int choice, item, max_size;
    QUEUE* queue = NULL;

    printf("Enter the maximum size of the queue: ");
    scanf("%d", &max_size);

    queue = create(max_size);

    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d", &item);
                enqueue(queue, item);
                break;
            case 2:
                item = dequeue(queue);
                printf("Dequeued element: %d\n", item);
                break;
            case 3:
                display(queue);
                break;
            case 4:
                liberate(queue);
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }

    return 0;
}