/*
 * =====================================================================================
 *
 *       Filename:  chmod.c
 *
 *    Description:  chmod, fchmod, fchmodat
 *
 *        Version:  1.0
 *        Created:  03/30/2018 09:04:26 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  AlanKohan (AK), wood@khan.ren
 *   Organization:  www.khan.ren/wiki
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>

#define MAXSIZE 4096

static void
err_doit(int error, int errorflag, const char *fmt, va_list ap)
{
    char    buf[MAXSIZE];

    vsnprintf(buf, MAXSIZE - 1, fmt, ap);
    if (errorflag) {
        snprintf(buf, MAXSIZE - strlen(buf) - 1,
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

int main(void)
{
    struct stat     statbuf;

    /* turn on set-group-ID and turn off group-execute */

    if (stat("foo", &statbuf) < 0) {
        err_sys("stat error for foo");
    }
    if (chmod("foo", (statbuf.st_mode & ~S_IXGRP) | S_ISGID) < 0) {
        err_sys("chmod error for foo");
    }

    /* set absolute mode to "rw-r--r--" */

    if (chmod("bar", S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH) < 0) {
        err_sys("chmod error for bar");
    }

    exit(0);
}
