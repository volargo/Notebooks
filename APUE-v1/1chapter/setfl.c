/*
 * =====================================================================================
 *
 *       Filename:  set_fl.c
 *
 *    Description:  specify file descriptor then open one or mores file status flag
 *
 *        Version:  1.0
 *        Created:  08/12/2017 05:48:32 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (Loong), urloong@163.com
 *   Organization:  zy.imau.edu.cn
 *
 * =====================================================================================
 */
#include "apue.h"
#include <fcntl.h>

/* 
 * If hasn't apue.h
 */
#ifndef _APUE_H
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <fcntl.h>

#define MAXLINE 4096

/*
 * Print a message and return to caller.
 * Caller specifies "errnoflag".
 */
static void
err_doit(int errnoflag, int error, const char *fmt, va_list ap) {
    char        buf[MAXLINE];

    vsnprintf(buf, MAXLINE, fmt, ap);

    if (errnoflag) {
        snprintf(buf+strlen(buf), MAXLINE-strlen(buf), ": %s", strerror(error));
    }
    strcat(buf, "\n");
    fflush(stdout);      /* in case stdout and stderr are the same */
    fputs(buf, stderr);
    fflush(NULL);        /* flushes all stdio output streams */
}

void
err_sys(const char *fmt, ...) {
    va_list     ap;

    va_start(ap, fmt);
    err_doit(1, errno, fmt, ap);
    va_end(ap);
    exit(1);
}

#endif      /* _APUE_H */

void set_fl(int, int);      /* flags are files status flags to turn on */

int
main(void)
{
    exit(0);
}

void
set_fl(int fd, int flags) {
    int         val;

    if ((val = fcntl(fd, F_GETFL, 0)) < 0) {
        err_sys("fcntl F_GETFL error");
    }

    val |= flags;       /* turn on flags */

    if (fcntl(fd, F_SETFL, val) < 0) {
        err_sys("fcntl F_SETFL error");
    }
}
