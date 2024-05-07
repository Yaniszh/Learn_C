/*
 * Package Name: exercise6-1
 *
 * File Name: main.c
 *
 * Abstract:
 * Exercise 6-1. Our version of getword does not properly handle underscores, string constants, comments, or
 * preprocessor control lines. Write a better version.
 *
 * Created: yanice  2024/4/9
 *
 * History: yanice  2024/4/12
 *
 */
    

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "ch.h"

#define MAXWORD 100
#define NKEYS (sizeof keytab / sizeof (struct key))

struct key {
    char *keyword;
    int count;
} keytab[] = {
    { "auto",       0 },
    { "break",      0 },
    { "case",       0 },
    { "char",       0 },
    { "const",      0 },
    { "continue",   0 },
    { "default",    0 },
    { "unsigned",   0 },
    { "void",       0 },
    { "volatile",   0 },
    { "while",      0 }
};

int getword(char *, int);
int binsearch(char *, struct key *, int);

int main(int argc, const char * argv[]) {
    int n;
    char word[MAXWORD];
    
    while (getword(word, MAXWORD) != EOF) {
        if (isalpha(word[0])) {
            if ((n = binsearch(word, keytab, NKEYS)) >= 0) {
                keytab[n].count++;
            }
        }
    }
    for (n = 0; n < NKEYS; n++) {
        if (keytab[n].count >0) {
            printf("%4d %s\n", keytab[n].count, keytab[n].keyword);
        }
    }
    return 0;
}

/* binsearch: find word in tab[0]...tab[n-1] */
int binsearch(char *word, struct key tab[], int n)
{
    int cond;
    int low, high, mid;
    
    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if ((cond = strcmp(word, tab[mid].keyword)) < 0) {
            high = mid - 1;
        } else if (cond > 0) {
            low = mid + 1;
        } else {
            return mid;
        }
    }
    return -1;
}

/* getword: get next word or character form input */
int getword(char *word, int lim)
{
    
    int c, getch(void);
    void un_getch(int);
    char *w = word;
    
    while (isspace(c = getch())) {
        ;
    }
    
    /* handle string constants */
    if (c == '"' || c == '\'') {
        if (c == '"') {
            while ((c = getch()) != '"') {
                if (c == '\\') {
                    c = getch();
                }
            }
        } else {
            while ((c = getch()) != '\'') {
                if (c == '\\') {
                    c = getch();
                }
            }
        }
    }
    
    /* handle comments */
    if (c == '/') {
        int c2, c3 = 0;
        if ((c2 = getch()) == '*') {
            while ((c2 = getch()) != '*' ? 1 : (c3 = getch()) != '/') {
                if (c2 == '*') {
                    un_getch(c3);
                }
            }
            c = c3;
        } else if (c2 == '/'){
            while ((c3 = getch()) != '\n') {
                ;
            }
        } else {
            un_getch(c2);
        }
    }
    
    /* handle preprocessor control lines */
    if (c == '#') {
        while ((c = getch()) != '\n') {
            ;
        }
    }
    
    if (c != EOF) {
        *w++ = c;
    }
    
    if (!isalpha(c) && c != '_') {
        *w = '\0';
        return c;
    }
    
    for (; --lim > 0; w++) {
        if (!isalnum(*w = getch()) && *w != '_') {
            un_getch(*w);
            break;
        }
    }
    *w = '\0';
    return word[0];
}
