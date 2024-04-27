/*
 * Package Name: exercise7-7
 *
 * File Name: main.c
 *
 * Abstract:
 * Exercise 7-7. Modify the pattern finding program of Chapter 5 to take its input from a set of named files or,
 * if no files are named as arguments, from the standard input. Should the file name be printed when a matching
 * line is found?
 *
 * Created: yanice  2024/4/20
 * xxx
 * History: null    null
 *
 */
    

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXLINE 1000
#define MAXFILE 10

int  c      =  -1;
int  except =   0;
int  number =   0;
int  found  =   0;

static void find(char *, const char*, FILE *);

/* find: print lines that match pattern from 1st arg */
int main(int argc, const char * argv[]) {
    char line[MAXLINE];
    
    FILE *fp;
    const char *filename[MAXFILE];
    int nfliename = 0;
    
    while (--argc > 0 && ((*++argv)[0] == '-' || *argv[0] == '+')) {
        if (*argv[0] == '-') {
            while ((c = *++argv[0])) {
                switch (c) {
                    case 'x':
                        except = 1;
                        break;
                    case 'n':
                        number = 1;
                        break;
                    default:
                        printf("find: illegal option %c\n", c);
                        argc = 0;
                        found = -1;
                        break;
                }
            }
        } else {
            filename[nfliename++] = ++argv[0];
        }
    }
    if (argc != 1) {
        printf("Usage: find -x -n [+filename] pattern\n");
        exit(1);
    } else {
        if (nfliename > 0) {
            while (nfliename-- > 0) {
                if ((fp = fopen(filename[nfliename], "r")) != NULL) {
                    printf("%s:\n", filename[nfliename]);
                    find(line, *argv, fp);
                    fclose(fp);
                } else {
                    fprintf(stderr, "find: can't open %s\n", filename[nfliename]);
                }
            }
        } else {
            find(line, *argv, stdin);
        }
    }
    return 0;
}

static void find(char *line, const char *pattern, FILE *fp)
{
    long lineno = 1;
    
    while (fgets(line, MAXLINE, fp) != NULL) {
        if ((strstr(line, pattern) != NULL) != except) {
            if (number) {
                printf("%ld:", lineno);
                found++;
            }
            printf("%s",line);
        }
    }
}
