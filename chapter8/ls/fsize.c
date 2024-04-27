/*
 * Package Name: ls
 *
 * File Name: fsize.c
 *
 * Abstract:
 * 
 *
 * Created: yanice  2024/4/25
 *
 * History: null    null
 *
 */
    

#include <stdio.h>
#include <sys/dirent.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATH 1024

void fsize(const char *);
int stat(const char *, struct stat *);
void dirwalk(const char *, void(*fcn)(const char *));

int main(int argc, const char * argv[]) {
    if (argc ==1) {
        fsize(".");
    } else{
        while (--argc > 0) {
            fsize(*++argv);
        }
    }
    return 0;
}

void fsize(const char *name)
{
    struct stat stbuf;
    
    if (stat(name, &stbuf) == -1) {
        fprintf(stderr, "fsize: can't access %s\n", name);
        return;
    }
    if (S_ISDIR(stbuf.st_mode)) {
        dirwalk(name, fsize);
    }
    printf("%8lld %s\n", stbuf.st_size, name);
}

void dirwalk(const char *dir, void(*fcn)(const char *))
{
    char name[MAX_PATH];
    typedef struct dirent Dirent;
    Dirent *dp;
    DIR *dfd;
    if ((dfd = opendir(dir)) == NULL) {
        fprintf(stderr, "dirwalk: can't open %s\n", dir);
    }
    while ((dp = readdir(dfd)) != NULL) {
        if (strcmp(dp->d_name, ".") == 0
         || strcmp(dp->d_name, "..") == 0) {
            continue;
        }
        if (strlen(dir)+strlen(dp->d_name)+2 > sizeof(name)) {
            fprintf(stderr, "dirwalk: name %s%s too long\n", dir, dp->d_name);
        } else {
            sprintf(name, "%s%s:",dir, dp->d_name);
            (*fcn)(name);
        }
    }
    closedir(dfd);
}
