/*Write a program to convert and print a given valid parenthesized infix arithmetic expression to postfix expression. The expression consists of single character operands and binary operators + - * /. Apply the concept of stack data structure to solve this problem. */

#include<ctype.h>
#include "stack.c"
#include<stdbool.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

bool opnd(char c){
    return (isalnum(c));
}

bool optr(char c) {
    return (c == '+' || c == '-' || c == '/' || c == '*');
}


int prec(char c) {
    switch(c) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        default: return -1;
    }
}

char* postfix(char* infix){
    char* postfix = (char*)malloc(strlen(infix)*sizeof(char));
    int ind = 0;
    STACK* ops = create(30);
    for(int i = 0; infix[i] != '\0'; i++){
        char cur = infix[i];
        if(opnd(cur)) {
            postfix[ind++] = cur;
        }
        else if(cur == '(') {
            push(ops,cur);
        }
        else if(cur == ')') {
            while((!empty(ops)) && peek(ops)!='('){
                postfix[ind++] = pop(ops);
            }
            char garbage = pop(ops);
        }
        else if(optr(cur)) {
            while((!empty(ops)) && (prec(peek(ops)) >= prec(cur))) {
                postfix[ind++] = pop(ops);
            }
            push(ops,cur);
        }
    }
    while(!empty(ops)) {
        postfix[ind++] = pop(ops);
    }
    postfix[ind++] = '\0';
    liberate(ops);
    return postfix;
}

int main() {
    char infix[100];

    printf("Enter the infix expression: ");
    scanf("%[^\n]", infix);

    char* postfix_expr = postfix(infix);

    printf("The postfix expression is: %s\n", postfix_expr);

    free(postfix_expr);

    return 0;
}