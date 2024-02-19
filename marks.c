/*Write a C program to create memory space to read 'n' marks (float) details. Ask the user if marks have to be entered for more than ‘n’ students. If 'yes', then create extra memory space and add data to the array of marks.  Print all the marks. */

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int* inp(int* arr, int size, int k){
    for(int i = k; i < size; i++){
        scanf("%d",(arr+i));
    }
    return arr;
}

void display(int* arr, int size){
    for(int i = 0; i < size; i++){
        printf(" %d",*(arr+i));
    }
    printf("\n");
}

int main(void){
    int num;
    char choice;
    int k = 0;
    printf("Enter the number of marks to be entered: ");
    scanf("%d",&num);
    int* m = (int*)malloc(num*sizeof(int));
    printf("Enter the marks: ");
    m = inp(m,num,k);
    display(m, num);
    while(1){
        printf("Do you want to enter more marks? (y/n)\n");
        scanf(" %c",&choice);
        if(choice == 'y'){
            k = num;
            num = num + 5;     
            m = (int*)realloc(m,num*sizeof(int));       
            printf("Enter 5 more entries: ");
            m = inp(m,num,k);
        }
        if(choice == 'n'){
            display(m, num);
            printf("Exiting...");
            exit(0);
        }
    }
}