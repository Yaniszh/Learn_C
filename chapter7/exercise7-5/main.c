/*
 * Package Name: exercise7-5
 *
 * File Name: main.c
 *
 * Abstract:
 * Exercise 5-5. Rewrite the postfix calculator of Chapter 4 to use scanf and/or sscanf to do the input and
 * number conversion.
 *
 * Created: yanice  2024/4/20
 *
 * History: null    null
 *
 */


#include <stdio.h>
#include <stdlib.h>     /* for atof() */
#include "calc.h"


/* postfix calculator */
int main(int argc, const char * argv[]) {
    int type;
    double op2;
    char s[MAXOP];
    
    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0) {
                    push(pop() / op2);
                }
                else {
                    printf("error: zero divisor\n");
                }
                break;
            case '\n':          /* output result */
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unkown command %s\n", s);
                break;
        }
    }
    printf("\t%.8g\n", pop());
    return 0;
}
