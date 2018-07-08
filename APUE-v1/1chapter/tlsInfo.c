/*
 * =====================================================================================
 *
 *       Filename:  tls.c
 *
 *    Description:  specify argument and print file type
 *
 *        Version:  1.0
 *        Created:  08/14/2017 01:35:28 PM
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
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAXLINE 4096

static void err_doit(int, int, const char *, va_list);
void err_ret(const char *, ...);

int
main(int argc, char *argv[])
{
    int         i;
    struct stat buf;
    char        *ptr;

    for (i = 1; i < argc; i++) {
        printf("%s: ", argv[i]);
        if (lstat(argv[i], &buf) < 0) {
            err_ret("lstat error");
            continue;
        }
        if (S_ISREG(buf.st_mode))
            ptr = "regular";
        else if (S_ISDIR(buf.st_mode))
            ptr = "directory";
        else if (S_ISBLK(buf.st_mode))
            ptr = "block special";
        else if (S_ISFIFO(buf.st_mode))
            ptr = "fifo";
        else if (S_ISLNK(buf.st_mode))
            ptr = "symbolic link";
        else if (S_ISSOCK(buf.st_mode))
            ptr = "socket";
        else
            ptr = "** unknow mode **";
        printf("%s\n", ptr);
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
err_ret(const char *fmt, ...) {
    va_list     ap;

    va_start(ap, fmt);
    err_doit(1, errno, fmt, 0);
    va_end(ap);
}
