/*
 * Package Name: exercise8-1
 *
 * File Name: main.c
 *
 * Abstract:
 * Exercise 8−1. Rewrite the program cat from Chapter 7 using read, write, open, and close instead of
 * their standard library equivalents. Perform experiments to determine the relative speeds of the two versions.
 *
 * Created: yanice  2024/4/22
 *
 * History: null    null
 *
 */
    

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <time.h>
#include <stdarg.h>

void error(char *, ...);

int main(int argc, const char * argv[]) {
    clock_t start, end;
    double prog_run_time;
    
    start = clock();
    
    int fd;
    void filecopy(int, int);
    
    const char *prog = argv[0];
    
    if (argc == 1) {
        filecopy(0, 1);
    } else {
        while (--argc > 0) {
            if ((fd = open(*++argv, O_RDONLY)) == -1) {
                fprintf(stderr, "error: %s can't open %s\n", prog, *argv);
                exit(1);
            } else {
                filecopy(fd, 1);
                close(fd);
            }
        }
    }
    if (ferror(stdout)) {
        fprintf(stderr, "error: %s error writing stdout\n", prog);
    }
    end = clock();
    prog_run_time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("%s run time: %f\n", prog, prog_run_time);
    exit(0);
}

void filecopy(int ifd, int ofd)
{
    char *buf[BUFSIZ];
    int n;
    while ((n = (int)read(ifd, buf, BUFSIZ)) > 0) {
        if(write(ofd, buf, n) != n) {
            error("%s: write error");
        }
    }
}

void error(char *fmt, ...)
{
    va_list args;
    
    va_start(args, fmt);
    fprintf(stderr, "error: ");
    vfprintf(stderr, fmt, args);
    fprintf(stderr, "\n");
    va_end(args);
    
    exit(1);
}

/*
 * unistd.h_time
 * 1            0.000115
 * 2            0.000087
 * 3            0.000107
 * 4            0.000169
 * avg:         0.000119.5
 *
 * stdio.h_time
 * 1            0.000760
 * 2            0.000714
 * 3            0.000507
 * 4            0.000597
 * avg:         0.000644.5
 *
 * faster:      5.39
 */
