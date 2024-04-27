/*
 * Package Name: exercise8-2
 *
 * File Name: _fillbuf.c
 *
 * Abstract:
 * Exercise 8-2. Rewrite fopen and _fillbuf with fields instead of explicit bit operations. Compare code
 * size and execution speed.
 *
 * Created: yanice  2024/4/23
 *
 * History: null    null
 *
 */
    

#include "file.h"
#include <stdlib.h>
#include <unistd.h>

int _fillbuf(FILE *fp)
{
    int bufsize;
    
    if (fp->flag._READ == 0 ||
        fp->flag._EOF  == 1 ||
        fp->flag._ERR  == 1) {
        return EOF;
    }
    bufsize = fp->flag._UNBUF == 1 ? 1 : BUFSIZ;
    if (fp->base == NULL) {
        if ((fp->base = (char *)malloc(bufsize)) == NULL) {
            return EOF;
        }
    }
    fp->ptr = fp->base;
    fp->cnt = read(fp->fd, fp->ptr, bufsize);
    if (--fp->cnt == -1) {
        if (fp->cnt == -1) {
            fp->flag._EOF = 1;
        } else {
            fp->flag._ERR = 1;
        }
        fp->cnt = 0;
        return EOF;
    }
    return (unsigned char) *fp->ptr++;
}
