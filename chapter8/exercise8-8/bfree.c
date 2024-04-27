/*
 * Package Name: exercise8-8
 *
 * File Name: bfree.c
 *
 * Abstract:
 * Exercise 8-8. Write a routine bfree(p,n) that will free any arbitrary block p of n characters into the free
 * list maintained by malloc and free. By using bfree, a user can add a static or external array to the free
 * list at any time.
 *
 * Created: yanice  2024/4/27
 *
 * History: null    null
 *
 */
    

#include <stdio.h>

typedef long Align;

typedef union header {
    struct {
        union header *ptr;
        unsigned size;
    } s;
    Align x;
} Header;


void free(void *);

unsigned bfree(void *p, unsigned n)
{
    Header *hp;
    
    if (n < sizeof(Header)) {
        return 0;
    }
    hp = (Header *)p;
    hp->s.size = n / sizeof(Header);
    free((void *)(hp+1));
    return hp->s.size;
}
