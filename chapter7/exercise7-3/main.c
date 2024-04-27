/*
 * Package Name: exercise7-3
 *
 * File Name: main.c
 *
 * Abstract:
 * Exercise 7-3. Revise minprintf to handle more of the other facilities of printf.
 *
 * Created: yanice  2024/4/19
 *
 * History: null    null
 *
 */
    

#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>

#define LOCALFMT    100

void minprintf(char *fmt, ...);

int main(int argc, const char * argv[]) {
    minprintf("%d\n", 100);
    return 0;
}

void minprintf(char *fmt, ...)
{
    va_list ap;
    char *p, *sval;
    char localfmt[LOCALFMT];
    int i, ival;
    unsigned uval;
    double dval;
    
    va_start(ap, fmt);
    for (p = fmt; *p; p++) {
        if (*p != '%') {
            putchar(*p);
            continue;
        }
        
        i = 0;
        localfmt[i++] = '%';
        while (*(p+1) && !isalpha(*(p+1))) {
            localfmt[i++] = *++p;
        }
        localfmt[i++] = *(p+1);
        localfmt[i] = '\0';
        switch (*++p) {
            case 'd':
            case 'i':
                ival = va_arg(ap, int);
                printf(localfmt, ival);
                break;
            case 'f':
                dval = va_arg(ap, double);
                printf(localfmt, dval);
                break;
            case 's':
                sval = va_arg(ap, char *);
                printf(localfmt, sval);
                break;
            case 'o':
            case 'x':
            case 'X':
            case 'u':
                uval = va_arg(ap, unsigned);
                printf(localfmt, uval);
                break;
            default:
                printf(localfmt);
                break;
        }
    }
}
