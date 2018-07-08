/*
 * =====================================================================================
 *
 *       Filename:  tlink.c
 *
 *    Description:  test unlink function
 *
 *        Version:  1.0
 *        Created:  08/17/2017 08:40:38 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (Loong), urloong@163.com
 *   Organization:  zy.imau.edu.cn
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

#define MAXLINE 4096

static void err_doit(int, int, const char *, va_list);
void err_sys(const char *, ...);

int
main(int argc, char *argv[])
{
    if (argc != 2) {
        err_sys("usage: command new-filename");
    }

    if (open(argv[1], O_RDWR) < 0) {
        err_sys("open error for %s", argv[1]);
    }

    if (unlink(argv[1]) < 0) {
        err_sys("unlink error for %s", argv[1]);
    }
    printf("file unlinked\n");
    sleep(5);
    printf("done\n");

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

/* Test way:
 * ----------------------------------------------------------------------
 *  eg1 $: ls -l [filename]
 *        #file information
 *      $: df /home
 *        # view avilable
 *      $: ./a.out tempfile &
 *        # program output a message
 *      $: df /home
 *        # view aviable
 * ----------------------------------------------------------------------*/
