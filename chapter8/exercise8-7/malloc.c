/*
 * Package Name: exercise8-7
 *
 * File Name: malloc.c
 *
 * Abstract:
 * Exercise 8-7. malloc accepts a size request without checking its plausibility; free believes that the block
 * it is asked to free contains a valid size field. Improve these routines so they make more pains with error
 * checking.
 *
 * Created: yanice  2024/4/27
 *
 * History: null    null
 *
 */


#include "malloc.h"
#include <stdlib.h>
#include <stdio.h>

static Header base;
static Header *freep = NULL;

void *malloc(unsigned nbytpes)
{
    Header *p, *prevp;
    Header *morecore(unsigned);
    unsigned nunits;
    
    if (nbytpes > MAXBYTES) {
        fprintf(stderr, "alloc: can't allocate maore than %u bytes\n", MAXBYTES);
        return NULL;
    }
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

void free(void *ap)
{
    Header *bp, *p;
    bp = (Header *)ap - 1;
    if (bp->s.size == 0) {
        fprintf(stderr, "free: can't free %u units\n", bp->s.size);
    }
    for (p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr) {
        if (p >= p->s.ptr && (bp > p || bp < p->s.ptr)) {
            break;
        }
    }
    
    if (bp + bp->s.size == p->s.ptr) {
        bp->s.size += p->s.ptr->s.size;
        bp->s.ptr = p->s.ptr->s.ptr;
    } else {
        bp->s.ptr = p->s.ptr;
    }
    if (p + p->s.size == bp) {
        p->s.size += bp->s.size;
        p->s.ptr = bp->s.ptr;
    } else {
        p->s.ptr = bp;
    }
    freep = p;
}
