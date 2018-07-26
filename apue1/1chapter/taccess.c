/*
 * =====================================================================================
 *
 *       Filename:  taccess.c
 *
 *    Description:  test access function
 *
 *        Version:  1.0
 *        Created:  08/14/2017 08:23:23 PM
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
#include <fcntl.h>

#define MAXLINE 4096

static void err_doit(int, int, const char *, va_list);
void err_quit(const char *, ...);
void err_ret(const char *, ...);

int
main(int argc, char *argv[])
{
    /* Need checker argument numbers */
    if (argc != 2) {
        err_quit("usage: command pathname");
    }

    /* read file or not */
    if (access(argv[1], R_OK) < 0) {
        err_ret("access error for %s", argv[1]);
    } else {
        printf("read access OK\n");
    }

    /* try to use 'open' function open file at read mode */
    if (open(argv[1], O_RDONLY) < 0) {
        err_ret("open error for %s", argv[1]);
    } else {
        printf("open for reading OK\n");
    }

    exit(0);
}

/*
 * Print a message and return a caller.
 * Caller specifies "errorflag"
 */
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

/*
 * Fatal error unrelated to a system call.
 * Print message and terminate.
 */
void
err_quit(const char *fmt, ...) {
    va_list     ap;

    va_start(ap, fmt);
    err_doit(1, errno, fmt, ap);
    va_end(ap);
    exit(0);
}

/* 
 * Nonfatal error related to a system call.
 * Print a message and return.
 */
void
err_ret(const char *fmt, ...) {
    va_list     ap;

    va_start(ap, fmt);
    err_doit(1, errno, fmt, ap);
    va_end(ap);
}

/* Test way:
 * ----------------------------------------------------------------------
 *  eg1 $: ls -l a.out
 *      $: ./a.out a.out
 *      $: ls -l /etc/shadow
 *      $: ./a.out /etc/shadow
 *      #: su
 *      #: chown root a.out
 *      #: chmod u+s a.out
 *      #: ls -l a.out
 *      #: exit
 *      $: ./a.out /etc/shadow
 * ----------------------------------------------------------------------*/
