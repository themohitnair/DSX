/*Write a C program to create memory space to read 'n' marks (float) details. Ask the user if marks have to be entered for more than ‘n’ students. If 'yes', then create extra memory space and add data to the array of marks.  Print all the marks. */

#include<stdio.h>
#include<stdlib.h>

int* create(int n){
    int* a;
    a = (int*)malloc(n*sizeof(int));
    return a;
}

void display(int* a, int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ",*(a+i));
    }
    printf("\n");
}

int main(void){
    int n;
    printf("Enter the number of marks to be entered: ");
    scanf("%d",&n);
    int* a = (int *)malloc(n*sizeof(int));
    int k = n;
    while(1) {
        for(int i = n-k; i < n; i++) {
            printf("Enter #%d: ", i);
            scanf("%d",(a+i));
        }
        char choice;
        printf("\nDo more marks to be entered? (y/n): ");
        fflush(stdin);
        scanf(" %c", &choice);
        if(choice=='y'){
            n += 5;
            a = (int*)realloc(a, n*sizeof(int));
            k = 5;
        }
        else {
            display(a,n);
            exit(0);
        }
    }
}