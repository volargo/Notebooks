/*
 * =====================================================================================
 *
 *       Filename:  access.c
 *
 *    Description:  how to use access function
 *
 *        Version:  1.0
 *        Created:  03/25/2018 10:51:12 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  AlanKohan (AK), wood@khan.ren
 *   Organization:  www.khan.ren/wiki
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

#define MAXSIZE 4096

static void
err_doit(int errnoflag, int error, const char *fmt, va_list ap)
{
    char    buf[MAXSIZE];

    vsnprintf(buf, MAXSIZE - 1, fmt, ap);

    if (errnoflag) {
        snprintf(buf+strlen(buf), MAXSIZE - strlen(buf) - 1,
                "%s", strerror(error));
    }
    strcat(buf, "\n");
    fflush(stdout);
    fputs(buf, stderr);
    fflush(NULL);
}

void
err_quit(const char *fmt, ...)
{
    va_list     ap;

    va_start(ap, fmt);
    err_doit(0, 0, fmt, ap);
    va_end(ap);
    exit(1);
}

void
err_ret(const char *fmt, ...)
{
    va_list     ap;

    va_start(ap, fmt);
    err_doit(1, errno, fmt, ap);
    va_end(ap);
}

int
main(int argc, char *argv[])
{
    if (argc != 2) {
        err_quit("usage: a.out <pathname>");
    }

    if(access(argv[1], R_OK) < 0) {
        err_ret("access error for %s", argv[1]);
    }
    else {
        printf("read access OK\n");
    }

    if (open(argv[1], O_RDONLY) < 0) {
        err_ret("open erro for %s", argv[1]);
    }
    else {
        printf("open for reading OK\n");
    }

    exit(EXIT_SUCCESS);
}
