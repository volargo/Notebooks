/*
 * =====================================================================================
 *
 *       Filename:  err.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/19/2017 12:23:35 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (Loong), urloong@163.com
 *   Organization:  zy.imau.edu.cn
 *
 * =====================================================================================
 */
#include "getopt_long.h"
#include <errno.h>
#include <fcntl.h>
#include <stdarg.h>
#include <string.h>

#define MAXLINE 4096

static void err_doit(int, int, const char *, va_list);

static void
err_doit(int errorflag, int error, const char *fmt, va_list ap) {
    char        buf[MAXLINE];

    vsnprintf(buf, MAXLINE, fmt, ap);

    if(errorflag) {
        snprintf(buf+strlen(buf), MAXLINE-strlen(buf), " %s", strerror(error));
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
    exit(1);
}
