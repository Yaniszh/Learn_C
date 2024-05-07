/*
 * Package Name: exercise6-2
 *
 * File Name: getword.c
 *
 * Abstract:
 * Define getword() function.
 *
 * Created: yanice  2024/4/12
 *
 * History: null    null
 *
 */
    

#include <stdio.h>
#include <ctype.h>
#include "getword.h"
#include "ch.h"

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
