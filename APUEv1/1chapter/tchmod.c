/*
 * =====================================================================================
 *
 *       Filename:  tchmod.c
 *
 *    Description:  test chmod function from <sys/stat.h>
 *
 *        Version:  1.0
 *        Created:  08/15/2017 04:29:49 PM
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
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>

#define MAXLINE 4096

typedef struct stat StatType;

static void err_doit(int, int, const char *, va_list);
void err_sys(const char *, ...);

int
main(int argc, char *argv[])
{
    if (argc != 2) {
        err_sys("usage: command filename");
    }

    StatType        statbuf;
    /* turn on set-group-ID and turn off group-execute */
    
    if (stat(argv[1], &statbuf) < 0) {
        err_sys("stat error for %s", argv[1]);
    }
    if (chmod(argv[1], (statbuf.st_mode & ~S_IXGRP) | S_ISGID) < 0) {
        err_sys("chmod error for %s", argv[1]);
    }

    /* set absolute mode to "rw-r--r--" */
    if (chmod("bar", S_IRGRP | S_IWUSR | S_IRGRP | S_IROTH) < 0) {
        err_sys("chmod error for bar");
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
