/*
 * Package Name: exercise7-8
 *
 * File Name: main.c
 *
 * Abstract:
 * Exercise 7-8. Write a program to print a set of files, starting each new one on a new page, with a title and a
 * running page count for each file.
 *
 * Created: yanice  2024/4/21
 *
 * History: null    null
 *
 */
    

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 100

int main(int argc, const char * argv[]) {
    FILE *fp;
    int lineno;
    char line[MAXLINE];
    
    const char *programe = *argv;
    if (argc == 1) {
        printf("%s: missing filename(s).\n", programe);
    }
    while (--argc > 0) {
        if ((fp = fopen(*++argv, "r")) == NULL) {
            fprintf(stderr, "%s: can't open %s\n", programe, *argv);
            exit(1);
        } else {
            lineno = 1;
            fprintf(stdout, "%s\n", *argv);
            while(fgets(line, MAXLINE, fp) != NULL) {
                printf("%d:", lineno++);
                fputs(line, stdout);
                if (strstr(line, "\f") != NULL) {
                    lineno = 1;
                }
            }
            putchar('\f');
            fclose(fp);
        }
    }
    return 0;
}
