/*
 * =====================================================================================
 *
 *       Filename:  tremove.c
 *
 *    Description:  test remove function
 *
 *        Version:  1.0
 *        Created:  08/17/2017 10:54:35 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (Loong), urloong@163.com
 *   Organization:  zy.imau.edu.cn
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <errno.h>
#include <unistd.h>

#define MAXLINE 4096

static void err_doit(int, int, const char *, va_list);
void err_sys(const char *, ...);

int
main(int argc, char *argv[])
{
    int     i;

    if (argc == 1) {
        err_sys("usage: command filename ...");
    }
    for (i = 1; i < argc; i++) {
        if (remove(argv[i]) < 0) {
            err_sys("remove error for %s", argv[1]);
        }
    }


    exit(0);
}

static void
err_doit(int errorflag, int error, const char *fmt, va_list  ap) {
    char        buf[MAXLINE];

    vsnprintf(buf, MAXLINE, fmt, ap);

    if(errorflag) {
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
