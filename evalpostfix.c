/*Write a program to evaluate a valid postfix expression using stack. Assume that the postfix expression is read as a single line consisting of non-negative single digit operands and binary operators. The operators are + - * and /. */

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>
#include "stack.c"

char itoc(int i) {
    return (char)(i+'0');   
}

char ctoi(char c) {
    return (int)(c-'0');
    
}

bool isoptr(char c) {
    return (c == '+'|'-'|'*'|'/');
}

bool isopnd(char c) {
    return (isalnum(c));
}

int evalpostfix(char* postfix) {
    STACK* ops = create(60);
    for(int i = 0; postfix[i]!='\0'; i++) {
        char cur = postfix[i];
        if(isopnd(cur)){
            push(ops,cur);
        }
        else if(isoptr(cur)) {
            int op2 = ctoi(pop(ops));
            int op1 = ctoi(pop(ops));
            switch(cur){
                case '+':
                push(ops,(itoc(op1+op2)));
                break;
                case '-':
                push(ops,(itoc(op1-op2)));
                break;
                case '*':
                push(ops, (itoc(op1*op2)));
                break;
                case '/':
                push(ops, (itoc(op1/op2)));
            }
        }
    }
    return ctoi(pop(ops));
}

int main() {
    char postfix[100];
    printf("Enter a postfix expression: ");
    scanf("%s", postfix);
    int result = evalpostfix(postfix);
    printf("Result of postfix expression evaluation: %d\n", result);
    return 0;
}
