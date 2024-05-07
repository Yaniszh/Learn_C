/*
 * Package Name: count_keywords
 *
 * File Name: ch.c
 *
 * Abstract:
 * Define getch() and un_getch() functions.
 *
 * Created: yanice  2024/4/8
 *
 * History: null    null
 *
 */
    

#include "ch.h"

char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
    return bufp ? buf[--bufp] : getchar();
}

void un_getch(int c)
{
    if (bufp >= BUFSIZE) {
        printf("un_getch: too many characters\n");
    } else {
        buf[bufp++] = c;
    }
}
