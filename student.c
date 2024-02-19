/*Define a structure student with fields name, usn, age, cgpa. Create an array of students and display them. Prompt the user for cgpa and display student details greater than or equal to the cgpa.*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    char* name;
    char* usn;
    float cgpa;
    int age;
}STUDENT;

STUDENT* create(int num){
    STUDENT* s = (STUDENT*)malloc(num*sizeof(STUDENT));

    for(int i = 0; i < num; i++){
        (s+i)->name = (char*)malloc(30*sizeof(char));
        (s+i)->usn = (char*)malloc(10*sizeof(char));
        printf("Enter the name of student %d: ",(i+1));
        scanf(" %[^\n]",(s+i)->name);
        printf("Enter the USN of student %d: ",(i+1));
        scanf(" %[^\n]",(s+i)->usn);
        printf("Enter the CGPA of student %d: ",(i+1));
        scanf("%f",&(s+i)->cgpa);
        printf("Enter the age of student %d: ",(i+1));
        scanf("%d",&(s+i)->age);
        printf("\n");
    }    
    return s;
}

void filter(STUDENT* s, float cgpa, int num){
    printf("\n");
    for(int i = 0; i < num; i++){
        if((s+i)->cgpa >= cgpa){
            printf("-----DETAILS OF STUDENT %d-----\n",(i+1));
            printf("Name: %s\nAge: %d\nUSN: %s\nCGPA: %f\n",(s+i)->name, (s+i)->age, (s+i)->usn, (s+i)->cgpa);
        }
    }
}

void display(STUDENT* s, int num){
    printf("\n");
    for(int i = 0; i < num; i++){
        printf("-----DETAILS OF STUDENT %d-----\n",(i+1));
        printf("Name: %s\nAge: %d\nUSN: %s\nCGPA: %f\n",(s+i)->name, (s+i)->age, (s+i)->usn, (s+i)->cgpa);
    }
}

int main(void){
    int num;
    printf("Enter the number of student records to be entered: ");
    scanf("%d",&num);
    STUDENT* s = create(num);
    display(s,num);
    float cgpa;
    printf("Enter the cutoff CGPA: ");
    scanf("%f", &cgpa);
    filter(s,cgpa,num);
}



