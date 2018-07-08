/*
 * =====================================================================================
 *
 *       Filename:  pt_stdio.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/20/2017 07:59:59 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (Loong), urloong@163.com
 *   Organization:  zy.imau.edu.cn
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>

#define MAXLINE 4096

static void err_doit(int, int, const char *, va_list);
void err_sys(const char *, ...);
void err_quit(int, const char *, ...);

void pr_stdio(const char *, FILE *);

int
main(int argc, char *argv[])
{
    FILE    *fp;

    if (argc != 2) {
        err_quit(EINVAL, "usage: command path-file");
    }

    fputs("enter any character\n", stdout);
    if (getchar() == EOF) {
        err_sys("getchar error:29:");
    }
    fputs("one line to standard error\n", stderr);

    pr_stdio("stdin", stdin);
    pr_stdio("stdout", stdout);
    pr_stdio("stderr", stderr);

    if ((fp = fopen(argv[1], "r")) == NULL) {
        err_sys("fopen error:38:");
    }
    if (getc(fp) == EOF) {
        err_sys("getc error:41:");
    }
    pr_stdio(argv[1], fp);

    exit(0);
}

void
pr_stdio(const char *name, FILE *fp) {
    printf("stream = %s, ", name);

    /* 
     * The following is nonportable
     */
    if (fp->_mode & _IO_UNBUFFERED) {       /* unix fp->_mode = fp->_IO_file_flag */
        printf("unbuffered");
    }
    else if (fp->_mode & _IO_LINE_BUF) {
        printf("line buffered");
    }
    else {
        printf("fully buffered");
    }
    printf(", buffer size = %ld\n", fp->_IO_buf_end - fp->_IO_buf_base);
}

static void
err_doit(int errorflag, int error, const char *fmt, va_list ap) {
    char        buf[MAXLINE];

    vsnprintf(buf, MAXLINE, fmt, ap);
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
}

void
err_quit(int error, const char *fmt, ...) {
    va_list     ap;

    va_start(ap, fmt);
    err_doit(1, error, fmt, ap);
    va_end(ap);
    exit(1);
}
