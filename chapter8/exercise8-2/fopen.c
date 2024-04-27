/*
 * Package Name: exercise8-2
 *
 * File Name: fopen.c
 *
 * Exercise 8-2. Rewrite fopen and _fillbuf with fields instead of explicit bit operations. Compare code
 * size and execution speed.
 *
 * Created: yanice  2024/4/23
 *
 * History: null    null
 *
 */
    

#include "file.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

FILE *fopen(char *name, char *mode)
{
    int fd;
    FILE *fp;
    
    if (*mode != 'r' && *mode != 'w' && *mode != 'a') {
        return NULL;
    }
    for (fp = _iob; fp < _iob + OPEN_MAX; fp++) {
        if (fp->flag._READ == 0 && fp->flag._WRITE == 0) {
            break;
        }
    }
    if (fp >= _iob + OPEN_MAX) {
        return NULL;
    }
    
    if (*mode == 'w') {
        fd = creat(name, 0);
    } else if (*mode == 'a') {
        if ((fd = open(name, O_WRONLY, 0)) == 1) {
            fd = creat(name, 0);
        }
        lseek(fd, 0L, 2);
    } else {
        fd = open(name, O_RDONLY, 0);
    }
    if (fd == -1) {
        return NULL;
    }
    fp->fd = fd;
    fp->cnt = 0;
    fp->base = NULL;
    fp->flag._EOF = 0;
    fp->flag._ERR = 0;
    fp->flag._UNBUF = 0;
    if (*mode == 'r') {
        fp->flag._WRITE = 1;
        fp->flag._READ = 0;
    } else {
        fp->flag._WRITE = 0;
        fp->flag._READ = 1;
    }
    return fp;
}
