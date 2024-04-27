/*
 * Package Name: exercise8-6
 *
 * File Name: malloc.h
 *
 * Abstract:
 *
 *
 * Created: yanice  2024/4/27
 *
 * History: null    null
 *
 */
    

#ifndef malloc_h
#define malloc_h

typedef long Align;

typedef union header {
    struct {
        union header *ptr;
        unsigned size;
    } s;
    Align x;
} Header;

void *malloc(unsigned);
void *calloc(unsigned, unsigned);

#endif /* malloc_h */
