/*Write a program to convert and print a given valid parenthesized infix arithmetic expression to postfix expression. The expression consists of single character operands and binary operators + - * /. Apply the concept of stack data structure to solve this problem. */

#include "stack.c"
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>
#include<string.h>

bool isoptr(char c) {
    return (c == '+'|'-'|'*'|'/');
}

bool isopnd(char c) {
    return (isalnum(c));
}

int prec(char c) {
    switch(c){
        case '+':
        case '-':
        return 1;
        case '/':
        case '*':
        return 2;
        default:
        return -1;
    }
}

char* postfix(char* infix) {
    char* postfix = (char*)malloc((strlen(infix)+1)*sizeof(char));
    int ind = 0;
    STACK* ops = create(30);
    for(int i = 0; infix[i] != '\0'; i++){
        char cur = infix[i];
        if(isopnd(cur)) {
            postfix[ind++] = cur;
        }
        else if(cur == '(') {
            push(ops, cur);
        }
        else if(cur == ')') {
            while(!(empty(ops)) && peek(ops)!='(') {
                postfix[ind++] = pop(ops);
            }
            char garbage = pop(ops);
        }
        else if(isoptr(cur)) {
            while(!empty(ops) && (prec(peek(ops)) >= prec(cur))) {
                postfix[ind++] = pop(ops);
            }
            push(ops,cur);
        }        
    }
    while(!(empty(ops))) {
        postfix[ind++] = pop(ops);
    }
    postfix[ind] = '\0';
    liberate(ops);
    return postfix;

}

int main(void) {
    char infix[60];
    printf("Enter the infix expression: ");
    scanf(" %[^\n]", infix);

    char* postfix_expr = postfix(infix);
    printf("Postfix expression: %s\n", postfix_expr);

    free(postfix_expr);

    return 0;
}