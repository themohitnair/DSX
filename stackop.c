/*Write a program to implement stack operations (Array implementation). Display the appropriate messages in case of exceptions. */

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct{
    char* s;
    int top;
    int max;
}STACK;

STACK* create(int max) {
    STACK* stack = (STACK*)malloc(sizeof(STACK));
    stack->top = -1;
    stack->max = max;
    stack->s = (char*)malloc(stack->max*sizeof(char));
    return stack;
}

bool empty(STACK* stack) {
    return (stack->top == -1);
}

bool full(STACK* stack) {
    return ((stack->top+1) == stack->max);
}

void xflow(STACK* stack) {
    if(full(stack)) {
        printf("Stack overflow\n");
        exit(0);
    }
    else if(empty(stack)) {
        printf("Stack underflow\n");
        exit(0);
    }
}

void push(STACK* stack, char item) {
    if(full(stack)){
        printf("Stack overflow\n");
        exit(0);
    }
    stack->s[++stack->top] = item;
}

char pop(STACK* stack) {
    if(empty(stack)){
        printf("Stack underflow\n");
        exit(0);
    }
    return stack->s[stack->top--];
}

char peek(STACK* stack){
    if(empty(stack)){
        printf("Stack underflow\n");
        exit(0);
    }
    return stack->s[stack->top];
}

void display(STACK* stack) {
    if(empty(stack)){
        printf("Stack underflow\n");
        exit(0);
    }
    for(int i = 0; i <= stack->top; i++) {
        printf("%c ",stack->s[i]);
    }
}

void liberate(STACK* stack){
    free(stack->s);
    free(stack);
}

int main() {
    int max;
    printf("Enter the maximum size of the stack: ");
    scanf("%d", &max);
    STACK* stack = create(max);

    int choice;
    char item;

    while (1) {
        printf("\nStack Operations\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item to push: ");
                scanf(" %c", &item);
                push(stack, item);
                printf("Item %c pushed into the stack.\n", item);
                break;
            case 2:                
                item = pop(stack);
                printf("Item %c popped from the stack.\n", item);                
                break;
            case 3:
                printf("Stack contents: ");
                display(stack);
                printf("\n");
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a number between 1 and 4.\n");
        }
    }

    return 0;
}
