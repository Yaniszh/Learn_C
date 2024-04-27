/*
 * Package Name: exercise8-2
 *
 * File Name: file.h
 *
 * Abstract:
 *
 *
 * Created: yanice  2024/4/23
 *
 * History: null    null
 *
 */
    

#ifndef file_h
#define file_h

//#define NULL        0
#define EOF         (-1)
#define BUFSIZ      1024
#define OPEN_MAX    20

typedef struct {
    unsigned int _READ   : 1;
    unsigned int _WRITE  : 1;
    unsigned int _UNBUF  : 1;
    unsigned int _EOF    : 1;
    unsigned int _ERR    : 1;
    
} Flags;

typedef struct _iobuf {
    long int cnt;
    char *ptr;
    char *base;
    Flags flag;
    int fd;
} FILE;

extern FILE _iob[OPEN_MAX];

#define stdin   (&_iob[0])
#define stdout  (&_iob[1])
#define stderr  (&_iob[2])


//enum _flags {
//    _READ   = 01,
//    _WRITE  = 02,
//    _UNBUF  = 04,
//    _EOF    = 010,
//    _ERR    = 020
//};

FILE *fopen(char *, char *);
int _fillbuf(FILE *);
int _flushbuf(int ,FILE *);

#define feof(p)     (((p)->flag & _EOF) != 0)
#define ferror(p) ((p)->flag _ERR) != 0)
#define fileno(p) ((p)->fd)

#define getc(p) (--(p)->cnt >= 0 \
            ? (unsigned char) *(p)->ptr++ : _fillbuf(p))
#define putc(x,p) (-(p)->cnt >= 0 \
            ? *(p)->ptr++ = (x) : _flushbuf((x),p))

#define getchar() getc(stdin)
#define putcher(x) putc((x), stdout)

#endif /* file_h */
