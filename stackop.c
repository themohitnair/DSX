/*Write a program to implement stack operations (Array implementation). Display the appropriate messages in case of exceptions. */

#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>

typedef struct{
    char* s;
    int top;
    int max;
}STACK;

STACK* create(int max){
    STACK* stack = (STACK*)malloc(sizeof(STACK));
    stack->max = max;
    stack->top = -1;
    stack->s = (char*)malloc(stack->max*sizeof(char));
    return stack;
}

bool empty(STACK* stack){
    return (stack->top == -1);
}

bool full(STACK* stack){
    return ((stack->top+1) == stack->max);
}

void push(STACK* stack, char item){
    if(full(stack)){
        printf("Stack is full. \n");
        return;
    }
    stack->s[++stack->top] = item;
}

char pop(STACK* stack){
    if(empty(stack)) {
        printf("Stack is empty. \n");
        return '\0';
    }
    return (stack->s[stack->top--]);
}

char peek(STACK* stack){
    if(empty(stack)) {
        printf("Stack is empty. \n");
        return '\0';
    }
    return (stack->s[stack->top]);
}

void liberate(STACK* stack){
    free(stack->s);
    free(stack);
}

void display(STACK* stack){
    if(empty(stack)) {
        printf("Stack is empty. \n");
        return;
    }
    for(int i = 0; i <= stack->top; i++){
        printf(" %c",stack->s[i]);
    }
    printf("\n");
}

int main() {
    int choice, max;
    char item;
    printf("Enter the maximum size of the stack: ");
    scanf("%d", &max);
    STACK* stack = create(max);
    
    do {
        printf("\nStack Operations Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Check if Stack is Empty\n");
        printf("5. Check if Stack is Full\n");
        printf("6. Display Stack\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the item to push: ");
                scanf(" %c", &item);
                push(stack, item);
                break;
            case 2:
                item = pop(stack);
                if(item != '\0')
                    printf("Popped item: %c\n", item);
                break;
            case 3:
                item = peek(stack);
                if(item != '\0')
                    printf("Top item: %c\n", item);
                break;
            case 4:
                if(empty(stack))
                    printf("Stack is empty.\n");
                else
                    printf("Stack is not empty.\n");
                break;
            case 5:
                if(full(stack))
                    printf("Stack is full.\n");
                else
                    printf("Stack is not full.\n");
                break;
            case 6:
                display(stack);
                break;
            case 7:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid choice.\n");
        }
    } while(choice != 7);

    liberate(stack);
    return 0;
}