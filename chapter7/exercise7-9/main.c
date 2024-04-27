/*
 * Package Name: exercise7-9
 *
 * File Name: main.c
 *
 * Abstract:
 * Exercise 7-9. Functions like isupper can be implemented to save space or to save time. Explore both
 * possibilities.
 *
 * Created: yanice  2024/4/21
 *
 * History: null    null
 *
 */
    

#include <stdio.h>
#define isupper(c) ((c >= 'A' && c <= 'Z') ? 1 : 0)

int main(int argc, const char * argv[]) {
    int r = isupper('A');
    printf("r: %d\n", r);
    return 0;
}
