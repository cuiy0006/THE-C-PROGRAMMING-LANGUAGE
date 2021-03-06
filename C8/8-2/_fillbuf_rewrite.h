#define NULL 0
#define EOF (-1)
#define BUFSIZE 1024
#define OPEN_MAX 20

typedef struct _flags
{
    unsigned int _READ;
    unsigned int _WRITE;
    unsigned int _UNBUF;
    unsigned int _EOF;
    unsigned int _ERR;
} FLAGS;

typedef struct _iobuf
{
    int cnt;
    char* ptr;
    char* base;
    FLAGS flag;
    int fd;
} FILE;

extern FILE _iob[OPEN_MAX];

#define stdin (&_iob[0])
#define stdout (&_iob[1])
#define stderr (&_iob[2])

int _fillbuf(FILE*);

#define feof(p) (((p)->flag._EOF) != 0)
#define ferror(p) (((p)->flag._ERR) != 0)
#define fileno(p) ((p)->fd)

#define getc(p) (--(p)->cnt >= 0 \
            ? (unsigned char) *(p)->ptr++ : _fillbuf(p))

#define getchar() getc(stdin)

FILE* fopen(const char* name, const char* mode);