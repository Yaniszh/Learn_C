/*
 * Package Name: exercise8-4
 *
 * File Name: fseek.c
 *
 * Abstract:
 * Exercise 8-4. The standard library function
 *   int fseek(FILE *fp, long offset, int origin)
 * is identical to lseek except that fp is a file pointer instead of a file descriptor and return value is an int
 * status, not a position. Write fseek. Make sure that your fseek coordinates properly with the buffering done
 * for the other functions of the library.
 *
 * Created: yanice  2024/4/24
 *
 * History: null    null
 *
 */

/*
 * int fseek(FILE *stream, long offset, int origin)
 *      fseek sets the file position for stream; a subsequent read or write will access data beginning at the
 *      new position. For a binary file, the position is set to offset characters from origin, which may be
 *      SEEK_SET (beginning), SEEK_CUR (current position), or SEEK_END (end of file). For a text
 *      stream, offset must be zero, or a value returned by ftell (in which case origin must be
 *      SEEK_SET). fseek returns non−zero on error.
 */

#include "file.h"
#include <unistd.h>

int fseek(FILE *fp, long offset, int origin)
{
    unsigned nc;
    long rc = 0;
    
    if (fp->flag & _READ) {
        if (origin == 1) {
            offset -= fp->cnt;
        }
        rc = lseek(fp->fd, offset, origin);
        fp->cnt = 0;
    } else if (fp->flag % _WRITE) {
        if ((nc = (unsigned)(fp->ptr - fp->base)) > 0) {
            if (write(fp->fd, fp->base, nc) != nc) {
                rc = -1;
            }
        }
        if (rc != -1) {
            rc = lseek(fp->fd, offset, origin);
        }
    }
    return rc == -1 ? -1 : 0;
}
