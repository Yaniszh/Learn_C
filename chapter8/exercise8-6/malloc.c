/*
 * Package Name: exercise8-6
 *
 * File Name: malloc.c
 *
 * Abstract:
 * Exercise 8-6. The standard library function calloc(n,size) returns a pointer to n objects of size size,
 * with the storage initialized to zero. Write calloc, by calling malloc or by modifying it.
 *
 * Created: yanice  2024/4/27
 *
 * History: null    null
 *
 */
    

#include "malloc.h"
#include <stdlib.h>

static Header base;
static Header *freep = NULL;
void *malloc(unsigned nbytpes)
{
    Header *p, *prevp;
    Header *morecore(unsigned);
    unsigned nunits;
    
    nunits = (nbytpes+sizeof(Header)-1)/sizeof(Header) + 1;
    if ((prevp = freep) == NULL) {
        base.s.ptr = freep = prevp = &base;
    }
    for (p = prevp->s.ptr; ; prevp = p, p = p->s.ptr) {
        if (p->s.size >= nunits) {
            if (p->s.size == nunits) {
                prevp->s.ptr = p->s.ptr;
            } else{
                p->s.size -= nunits;
                p += p->s.size;
                p->s.size = nunits;
            }
            freep = prevp;
            return (void *)(p+1);
        }
        if (p == freep) {
            if ((p = morecore(nunits)) == NULL) {
                return NULL;
            }
        }
    }
}

void *calloc(unsigned n, unsigned size)
{
    unsigned i, ns;
    char *p, *q;
    
    ns = n * size;
    if ((p = q = malloc(ns)) == NULL) {
        return p;
    }
    for (i = 0; i < ns; i++) {
        *p++ = 0;
    }
    return q;
}
