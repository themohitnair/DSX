/*Define a structure student with fields name, usn, age, cgpa. Create an array of students and display them. Prompt the user for cgpa and display student details greater than or equal to the cgpa.*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    char* name;
    char* usn;
    int age;
    float cgpa;
}STUDENT;

STUDENT* create (int n) {
    STUDENT* s = (STUDENT*)malloc(n*sizeof(STUDENT));
    for(int i = 0; i < n; i++) {
        s[i].name = (char*)malloc(30*sizeof(char));
        s[i].usn = (char*)malloc(10*sizeof(char));

        printf("Student #%d: \n", i+1);
        printf("Enter the full name of the student: ");
        scanf(" %[^\n]",s[i].name);

        printf("Enter the USN of the student: ");
        scanf(" %[^\n]",s[i].usn);

        printf("Enter the age of the student: ");
        scanf("%d",&s[i].age);

        printf("Enter the CGPA of the student: ");
        scanf("%f",&s[i].cgpa);

        printf("\n\n");
    }
    return s;
}

void cgpareq(float cgpa, STUDENT* s, int size) {
    for(int i = 0; i < size; i++){
        if(s[i].cgpa >= cgpa) {
            printf("Student #%d: \n", i+1);
            printf("Name: %s\n",s[i].name);
            printf("USN: %s\n",s[i].usn);
            printf("Age: %d\n",s[i].age);
            printf("CGPA: %0.2f",s[i].cgpa);
            printf("\n\n");
        }
    }
}

int main(void){
    int n;
    printf("Enter the number of students whose details are to be recorded: ");
    scanf("%d",&n);
    STUDENT* s;
    s = create(n);

    float cgpa;
    printf("Enter the CGPA filter level: ");
    scanf("%f",&cgpa);
    cgpareq(cgpa,s,n);
}