/*
 * Package Name: exercise8-5
 *
 * File Name: fsize.c
 *
 * Abstract:
 * Exercise 8-5. Modify the fsize program to print the other information contained in the inode entry.
 *
 * Created: yanice  2024/4/26
 *
 * History: null    null
 *
 */
    

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/dirent.h>

void dirwalk(char *, void (*fcn)(char *));

void fsize(char *name)
{
    struct stat stbuf;
    
    if (stat(name, &stbuf) == -1) {
        fprintf(stderr, "fsize: can't access %s\n", name);
        return;
    }
    if (S_ISDIR(stbuf.st_mode)) {
        dirwalk(name, fsize);
    }
    printf("%5llu %6o %3u %8lld %s\n", stbuf.st_ino, stbuf.st_mode, stbuf.st_nlink,
           stbuf.st_size, name);
}
