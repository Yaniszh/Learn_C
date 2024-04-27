/*
 * Package Name: exercise7-6
 *
 * File Name: main.c
 *
 * Abstract:
 * Exercise 7−6. Write a program to compare two files, printing the first line where they differ.
 *
 * Created: yanice  2024/4/20
 *
 * History: null    null
 *
 */
    

#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>

#define MAXLENGTHLINE   1000

int main(int argc, const char * argv[]) {
    char line1[MAXLENGTHLINE];
    char line2[MAXLENGTHLINE];
    
    FILE *fp1, *fp2;
    fp1 = fopen(argv[1], "r");
    fp2 = fopen(argv[2], "r");
    
    if (fp1 != NULL && fp2 != NULL) {
        do {
            fgets(line1, MAXLENGTHLINE, fp1);
            fgets(line2, MAXLENGTHLINE, fp2);
        } while (!feof(fp1) && !feof(fp2) && strcmp(line1, line2) == 0);
        if (feof(fp1) && !feof(fp2)) {
            printf("end of first file at line\n%s\n", line2);
        } else if (!feof(fp1) && feof(fp2)) {
            printf("end of second file at line\n%s\n", line1);
        } else if (!feof(fp1) && !feof(fp2)) {
            printf("line1: %s\n", line1);
            printf("line2: %s\n", line2);
        } else {
            printf("file1 is the same as file2.\n");
        }
    } else {
        fprintf(stderr, "%s: can not open %s, %s\n", argv[0], argv[1], argv[2]);
        exit(1);
    }
    if (ferror(fp1)) {
        fprintf(stderr, "%s: error reading fp1\n", argv[0]);
    }
    if (ferror(fp2)) {
        fprintf(stderr, "%s: error reading fp2\n", argv[0]);
    }
    fclose(fp1);
    fclose(fp2);
    exit(0);
}
