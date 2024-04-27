/*
 * Package Name: exercise7-1
 *
 * File Name: main.c
 *
 * Abstract:
 * Exercise 7-1. Write a program that converts upper case to lower or lower case to upper, depending on the
 * name it is invoked with, as found in argv[0].
 *
 * Created: yanice  2024/4/18
 *
 * History: null    null
 *
 */
    

#include <stdio.h>
#include <ctype.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

/*- misunderstanding -*/
//static void argv0toupper(char *[], char *);
//
//int main(int argc, const char * argv[]) {
//    char *argv0upper = (char *)malloc(strlen(argv[0])+1);
//    argv0toupper((char **)argv, argv0upper);
//    printf("argv[0]: %s\n", argv0upper);
//    return 0;
//}
//
//static void argv0toupper(char *argv[], char *argvupper)
//{
//    char *p = argv[0];
//    while ((*argvupper++ = toupper(*p++))) {
//    }
//}

int main(int argc, const char * argv[]) {
    int c;
    if (strcmp(argv[0], "./lower") == 0) {
        while ((c = getchar()) != EOF) {
            putchar(tolower(c));
        }
    } else if (strcmp(argv[0], "./upper") == 0) {
        while ((c = getchar()) != EOF) {
            putchar(toupper(c));
        }
    } else {
        printf("no match: argv[0] is %s\n", argv[0]);
    }
    return 0;
}

