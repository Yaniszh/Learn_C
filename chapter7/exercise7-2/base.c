/*
 * Package Name: exercise7-2
 *
 * File Name: base.c
 *
 * Abstract:
 * Base system
 *
 * Created: yanice  2024/4/19
 *
 * History: null    null
 *
 */
    

#include "base.h"
#include <ctype.h>
#include <stdio.h>

/* octal to decimal */
int otod(char *octal){
    int decimal = 0;
    while (*octal) {
        decimal = decimal * 8 + *octal - '0';
        octal++;
    }
    return decimal;
}

/* hexadecimal to decimal */
int xtod(char *hex)
{
    int decimal = 0;
    while (*hex) {
        if (isdigit(*hex)) {
            decimal = decimal * 16 + *hex - '0';
        } else {
            decimal = decimal * 16 + toupper(*hex) - 'A' + 10;
        }
        hex++;
    }
    return decimal;
}
