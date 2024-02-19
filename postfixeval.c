/*Write a program to evaluate a valid postfix expression using stack. Assume that the postfix expression is read as a single line consisting of non-negative single digit operands and binary operators. The operators are + - * and /. */

#include "stack.c"
#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int ctoi(char c){
    return (int)(c - '0');
}

char itoc(int i){
    return (char)(i + 48);
}

bool opnd(char c){
    return (isalnum(c));
}

bool optr(char c) {
    return (c == '+' || c == '-' || c == '/' || c == '*');
}

int eval_postfix(char* postfix){
    STACK* ops = create(60);
    for(int i = 0; postfix[i] != '\0'; i++){
        char cur = postfix[i];
        if(opnd(cur)) {
            push(ops, cur);
        }
        else if(optr(cur)) {
            int op2 = ctoi(pop(ops));
            int op1 = ctoi(pop(ops));
            switch(cur) {
                case '+':
                    push(ops,itoc(op1+op2));
                    break;
                case '-':
                    push(ops,itoc(op1-op2));
                    break;
                case '*':
                    push(ops,itoc(op1*op2));
                    break;
                case '/':
                    push(ops,itoc(op1/op2));
                    break;
                default:
            }
        }
    }
    return ctoi(pop(ops));
}

int main() {
    char postfix[100];

    printf("Enter the postfix expression: ");
    scanf("%s", postfix);

    int result = eval_postfix(postfix);

    printf("Result: %d\n", result);

    return 0;
}
