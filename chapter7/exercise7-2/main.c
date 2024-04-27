/*
 * Package Name: exercise7-2
 *
 * File Name: main.c
 *
 * Abstract:
 * Exercise 7-2. Write a program that will print arbitrary input in a sensible way. As a minimum, it should print
 * non−graphic characters in octal or hexadecimal according to local custom, and break long text lines.
 *
 * Created: yanice  2024/4/19
 *
 * History: null    null
 *
 */
    

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXLINE 100
#define OCTLEN  6       /* length of an octal value */


int main(int argc, const char * argv[]) {
    /*- misunderstanding -*/
//    char c;
//    int nline= 0;
//    while ((c = getch()) != EOF) {
//        if (nline >= 20) {
//            putchar('\n');
//            nline = 0;
//        }
//        nline++;
//        if (c == '\\') {
//            char d;
//            if ((d = getch()) == 'x' || d == 'X') {
//                char e;
//                if (isdigit(e = getch()) || (toupper(e) >= 'A' && toupper(e) <= 'F')) {
//                    char f;
//                    if (isdigit(f = getch()) || (toupper(f) >= 'A' && toupper(f) <= 'F')) {
//                        char *hex = (char *)malloc(3);
//                        char *p = hex;
//                        *p++ = e;
//                        *p++ = f;
//                        *p = '\0';
//                        putchar(xtod(hex));
//                        free((void *)hex);
//                    } else {
//                        putchar(c);
//                        putchar(d);
//                        putchar(e);
//                        putchar(f);
//                    }
//                } else {
//                    putchar(c);
//                    putchar(d);
//                    putchar(e);
//                }
//            } else if (d >= '0' && d <= '7') {
//                char e;
//                if ((e = getch()) >= '0' && e <= '7') {
//                    char f;
//                    if ((f = getchar()) >= '0' && f <= '7') {
//                        char *octal = (char *)malloc(3);
//                        char *p = octal;
//                        *p++ = d;
//                        *p++ = e;
//                        *p++ = f;
//                        *p = '\0';
//                        putchar(otod(octal));
//                        free((void *)octal);
//                    } else {
//                        putchar(c);
//                        putchar(d);
//                        putchar(e);
//                        putchar(f);
//                    }
//                } else {
//                    putchar(c);
//                    putchar(d);
//                    putchar(e);
//                }
//            } else {
//                putchar(c);
//                putchar(d);
//            }
//        } else {
//            if (c == '\n') {
//                nline = 0;
//            }
//            putchar(c);
//        }
//    }
    int c, pos;
    int inc(int, int);
    pos = 0;
    while ((c = getchar()) != EOF) {
        if (iscntrl(c) || c == ' ') {
            pos = inc(pos, OCTLEN);
            printf(" \\%03o ", c);
            if (c == '\n') {
                pos = 0;
                putchar(c);
            }
        } else {
            pos = inc(pos, 1);
            putchar(c);
        }
    }
    return 0;
}

int inc(int pos, int n)
{
    if (pos + n < MAXLINE) {
        return pos + n;
    } else {
        putchar('\n');
        return n;
    }
}

