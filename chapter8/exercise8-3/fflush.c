/*
 * Package Name: exercise8-3
 *
 * File Name: fflush.c
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

int fflush(FILE *fp)
{
    int rc = 0;
    if (fp < _iob || fp > _iob + OPEN_MAX) {
        return EOF;
    }
    if (fp->flag & _WRITE) {
        rc = _flushbuf(0, fp);
    }
    fp->ptr = fp->base;
    fp->cnt = BUFSIZ;
    return rc;
}
