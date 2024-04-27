/*
 * Package Name: exercise8-3
 *
 * File Name: _flushbuf.c
 *
 * Abstract:
 * Exercise 8-3. Design and write _flushbuf, fflush, and fclose.
 *
 * Created: yanice  2024/4/23
 *
 * History: null    null
 *
 */
    

#include "file.h"
#include <stdlib.h>
#include <unistd.h>

int _flushbuf(int x, FILE * fp)
{
    unsigned long nc;
    int bufsize;
    
    if (fp < _iob || fp >= _iob + OPEN_MAX) {
        return  EOF;
    }
    if ((fp->flag & (_WRITE | _ERR)) != _WRITE) {
        return EOF;
    }
    bufsize = (fp->flag & _UNBUF) ? 1 : BUFSIZ;
    if (fp->base == NULL) {
        if ((fp->base = (char *)malloc(bufsize)) == NULL) {
            fp->flag |= _ERR;
            return EOF;
        }
    } else {
        nc = fp->ptr - fp->base;
        if (write(fp->fd, fp->base, nc) != nc) {
            fp->flag |= _ERR;
            return EOF;
        }
    }
    
    fp->ptr = fp->base;
    *fp->ptr++ = (char)x;
    fp->cnt = BUFSIZ - 1;
    return x;
}
