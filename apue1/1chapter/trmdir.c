/*
 * =====================================================================================
 *
 *       Filename:  trmdir.c
 *
 *    Description:  test rmdir function from <sys/stat.h>
 *
 *        Version:  1.0
 *        Created:  08/18/2017 09:36:17 AM
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
#include <sys/stat.h>

#define MAXLINE 4096

static void err_doit(int, int, const char *, va_list);
void err_msg(const char *, ...);
void err_sys(const char *, ...);

int
main(int argc, char *argv[])
{
    int         i;

    if (argc < 2) {
        err_msg("usage: trmdir dir ...");
    }

    for (i = 1; i < argc; i++) {
        if (rmdir(argv[i]) < 0) {
            err_sys("rmdir error for %s", argv[i]);
            continue;
        }
    }
    exit(0);
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
err_msg(const char *fmt, ...) {
    va_list     ap;

    va_start(ap, fmt);
    err_doit(0, 0, fmt, ap);
    va_end(ap);
}
