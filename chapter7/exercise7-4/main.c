/*
 * Package Name: exercise7-4
 *
 * File Name: main.c
 *
 * Abstract:
 * Exercise 7-4. Write a private version of scanf analogous to minprintf from the previous section.
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

int minscanf(char *fmt, ...);

int main(int argc, const char * argv[]) {
    int day;
    int month;
    int year;
    minscanf("%d/%d/%d", &day, &month, &year);
    printf("day: %d\n", day);
    printf("month: %d\n", month);
    printf("year: %d\n", year);
    return 0;
}

int minscanf(char *fmt, ...)
{
    va_list ap;
    char *p, *sval;
    char localfmt[LOCALFMT];
    int nscanf, i, *ival;
    float *fval;
    
    va_start(ap, fmt);
    nscanf = 0;
    i = 0;
    for (p = fmt; *p ; p++) {
        while (*p == ' ' || *p == '\t') {
            continue;
        }
        
        if (*p != '%') {
            localfmt[i++] = *p;
            continue;
        }
        
        localfmt[i++] = '%';
        while (*(p+1) && !isalpha(*(p+1))) {
            localfmt[i++] = *++p;
        }
        localfmt[i++] = *(p+1);
        localfmt[i] = '\0';
        switch ((*++p)) {
            case 'd':
            case 'i':
            case 'o':
            case 'x':
                ival = va_arg(ap, int *);
                nscanf += scanf(localfmt, ival);
                break;
            case 'c':
            case 's':
                sval = va_arg(ap, char *);
                nscanf += scanf(localfmt, sval);
                break;
            case 'e':
            case 'f':
            case 'g':
                fval = va_arg(ap, float *);
                nscanf += scanf(localfmt, fval);
                break;
            default:
                nscanf += scanf(localfmt);
                break;
        }
    }
    va_end(ap);
    return nscanf;
}
