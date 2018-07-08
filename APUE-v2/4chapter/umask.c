/*
 * =====================================================================================
 *
 *       Filename:  umask.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/30/2018 08:35:16 PM
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
#include <errno.h>
#include <stdarg.h>
#include <fcntl.h>
#include <sys/stat.h>

#define MAXSIZE 4096

#define RWRWRW (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)

static void
err_doit(int error, int errorflag, const char *fmt, va_list ap)
{
    char    buf[MAXSIZE];

    vsnprintf(buf, MAXSIZE - 1, fmt, ap);
    if (errorflag) {
        snprintf(buf+strlen(buf), MAXSIZE - strlen(buf) - 1,
                "%s", strerror(error));
    }
    strcat(buf, "\n");
    fflush(stdout);
    fputs(buf, stdout);
    fflush(NULL);
}

void
err_sys(const char *fmt, ...)
{
    va_list     ap;

    va_start(ap, fmt);
    err_doit(1, errno, fmt, ap);
    va_end(ap);
}

int
main(void)
{
    umask(0);

    if (creat("foo", RWRWRW) < 0) {
        err_sys("create error for foo");
    }
    umask(S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
    if (creat("bar", RWRWRW) < 0) {
        err_sys("create error for bar");
    }

    exit(0);
}

/*
 * $: gcc umask.c
 * $: ./a.out
 * $: ls -l foo bar
 */
