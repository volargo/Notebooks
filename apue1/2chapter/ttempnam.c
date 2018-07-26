/*
 * =====================================================================================
 *
 *       Filename:  ttempnam.c
 *
 *    Description:  test tempnam function from <stdio.h>
 *
 *        Version:  1.0
 *        Created:  08/20/2017 10:37:40 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (Loong), urloong@163.com
 *   Organization:  zy.imau.edu.cn
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

#define MAXLINE 4096

void err_quit(int errorflag, int error, const char *, ...);

int
main(int argc, char *argv[])
{
    if (argc != 3) {
        err_quit(1, EINVAL, "usage: a.out <directory> <prefix>");
    }

    printf("%s\n", tempnam(argv[1][0] != ' ' ? argv[1] : NULL,
        argv[2][0] != ' ' ? argv[2] :NULL));

    exit(0);
}

void
err_quit(int errorflag, int error, const char *fmt, ...) {
    va_list     ap;
    char        buf[MAXLINE];

    va_start(ap, fmt);
    vsnprintf(buf, MAXLINE, fmt, ap);
    if (errorflag) {
        /* 
         * Set errno by man 3 errno view helper
         */
        snprintf(buf+strlen(buf), MAXLINE-strlen(buf), ": %s",
            strerror(error));
    }
    strcat(buf, "\n");
    fflush(stdout);
    fputs(buf, stderr);
    fflush(NULL);
    exit(1);
}
