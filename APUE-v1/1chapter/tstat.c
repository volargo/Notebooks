/*
 * =====================================================================================
 *
 *       Filename:  t.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/13/2017 09:34:01 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (Loong), urloong@163.com
 *   Organization:  zy.imau.edu.cn
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAXLINE 4096

static void err_doit(int, int, const char *, va_list);
void err_sys(const char *, ...);

int
main(int argc, char *argv[])
{
    int fd;

    if (argc != 2) {
        fprintf(stderr, "usage: command filename""\n");
        exit(EXIT_FAILURE);
    }
    
    if ((fd = open(argv[1], O_WRONLY)) < 0) {
        err_sys("open %s error", argv[1]);
    }

    struct stat     buf;
    fstat(fd, &buf);

    /* 
     * There are so many ways to print all infomation: 
     */
    printf("uid: %d\n", buf.st_uid);
    printf("dev: %ld\n", buf.st_dev);
    printf("ino: %ld\n", buf.st_ino);
#if 0
    struct stat p;
    fwrite(&p, sizeof(p), 1, stdout);
#endif
    close(fd);
    exit(0);
}

static void
err_doit(int errorflag, int error, const char *fmt, va_list ap) {
    char        buf[MAXLINE];

    vsprintf(buf, fmt, ap);

    if (errorflag) {
        snprintf(buf+strlen(buf), MAXLINE-strlen(buf), ": %s", strerror(error));
    }
    strcat(buf, "\n");
    fflush(stdout);
    fputs(buf, stderr);
    fflush(NULL);
}

void
err_sys(const char *fmt, ...) {
    va_list     ap;

    va_start(ap, fmt);
    err_doit(1, errno, fmt, ap);
    va_end(ap);
    exit(1);
}
