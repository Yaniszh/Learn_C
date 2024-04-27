/*
 * Package Name: cat
 *
 * File Name: main.c
 *
 * Abstract:
 * cat is used for printing files on the screen.
 *
 * Created: yanice  2024/4/22
 *
 * History: null    null
 *
 */
    

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(int argc, const char * argv[]) {
    clock_t start, end;
    double prog_run_time;
    
    start = clock();
    FILE *fp;
    void filecopy(FILE *, FILE *);
    const char *prog = argv[0];
    
    if (argc == 1) {
        filecopy(stdin, stdout);
    } else {
        while (--argc > 0) {
            if ((fp = fopen(*++argv, "r")) == NULL) {
                fprintf(stderr, "error: %s can't open %s\n", prog, *argv);
                exit(1);
            } else {
                filecopy(fp, stdout);
                fclose(fp);
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

void filecopy(FILE *ifp, FILE *ofp)
{
    int c;
    
    while ((c = getc(ifp)) != EOF) {
        putc(c, ofp);
    }
}
