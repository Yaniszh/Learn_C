/*
 * Package Name: exercise6-2
 *
 * File Name: addtnode.c
 *
 * Abstract:
 * Define addtree() function.
 *
 * Created: yanice  2024/4/12
 *
 * History: null    null
 *
 */


#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include "addtnode.h"

struct tnode *talloc(void);
char *str_dup(char *);

struct tnode *addtree(struct tnode *p, char *w)
{
    int cond = 0;
    
    if (p == NULL) {
        p = talloc();
        p->word = str_dup(w);
        p->count = 1;
        p->left = p->right = NULL;
    } else if ((cond = strcmp(w, p->word)) < 0) {
        p->left = addtree(p->left, w);
    } else if (cond == 0) {
        p->count++;
    } else  {
        p->right = addtree(p->right, w);
    }
    return p;
}

struct tnode *talloc(void)
{
    return (struct tnode *)malloc(sizeof(struct tnode));
}

char *str_dup(char *s)
{
    char *p;
    
    p = (char *) malloc(strlen(s) + 1);
    if (p != NULL) {
        strcpy(p, s);
    }
    return p;
}
