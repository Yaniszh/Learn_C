/*
 * Package Name: exercise7-5
 *
 * File Name: getop.c
 *
 * Abstract:
 * Define getop() function.
 *
 * Created: yanice  2024/4/20
 *
 * History: null    null
 *
 */
    

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "calc.h"

/* getop: get next character or numeric operand */
int getop(char s[])
{
    
    int rflag;
    rflag = scanf("%s", s);
    
    if (rflag == EOF) {
        return rflag;
    }
    if (isdigit(s[0]) || ((s[0] == '+' || s[0] == '-' || s[0] == '.') && s[1] != '\0')) {
        return NUMBER;
    }
    return s[0];
}
