/*
 * Package Name: exercise8-3
 *
 * File Name: fclose.c
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
#include <unistd.h>
#include <stdlib.h>


int fclose(FILE * fp)
/* fclose flushes any unwritten data for stream, discards any unread buffered input, frees any
 * automatically allocated buffer, then closes the stream. It returns EOF if any errors occurred, and zero
 * otherwise. */
{
    int rc;
    if ((rc = fflush(fp)) != EOF) {
        free(fp->base);
        fp->ptr = NULL;
        fp->base = NULL;
        fp->cnt = 0;
        fp->flag &= ~(_READ | _WRITE);
        fp->fd = 0;
    }
    return 0;
}
