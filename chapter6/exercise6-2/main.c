/*
 * Package Name: exercise6-2
 *
 * File Name: main.c
 *
 * Abstract:
 * Exercise 6-2. Write a program that reads a C program and prints in alphabetical order each group of variable
 * names that are identical in the first 6 characters, but different somewhere thereafter. Don't count words within
 * strings and comments. Make 6 a parameter that can be set from the command line.
 *
 * Created: yanice  2024/4/11
 *
 * History: yanice  2024/4/15
 *
 */
    

#include <stdio.h>
#include <ctype.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include "getword.h"
#include "addtnode.h"

#define NUMGROUP    6


struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *, int);
int getword(char *,int);

char *tempword = "\0";

int main(int argc, const char * argv[]) {
    struct tnode *root;
    char word[MAXWORD];
    int ngroup = (--argc && *(*++argv) == '-') ? atoi(++*argv) : NUMGROUP;
    
    root = NULL;
    while (getword(word, MAXWORD) != EOF) {
        if (isalpha(word[0])) {
            root = addtree(root, word);
        }
    }
    treeprint(root, ngroup);
    return 0;
}

void treeprint(struct tnode *p, int n)
{
    if (p !=NULL) {
        treeprint(p->left, n);
        if (strncmp(p->word, tempword, n) != 0) {
            putchar('\n');
        }
        printf("%4d %s\n", p->count, p->word);
        tempword = p->word;
        treeprint(p->right, n);
    }
}
