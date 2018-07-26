/*
 * =====================================================================================
 *
 *       Filename:  stat.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/25/2018 08:15:06 PM
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
#include <stdarg.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>

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
    fputs(buf, stdout);
    fflush(NULL);
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
    int         i;
    struct stat buf;
    char        *ptr;

    for (i = 1; i < argc; i++) {
        printf("%s: ", argv[i]);
        if (lstat(argv[1], &buf) < 0) {
            err_ret("lstat error");
            continue;
        }

        if (S_ISREG(buf.st_mode))
            ptr = (char*)"regular";
        else if (S_ISDIR(buf.st_mode))
            ptr = (char*)"directory";
        else if (S_ISCHR(buf.st_mode))
            ptr = (char*)"character special";
        else if (S_ISBLK(buf.st_mode))
            ptr = (char*)"block special";
        else if (S_ISFIFO(buf.st_mode))
            ptr = (char*)"fifo";
        else if (S_ISLNK(buf.st_mode))
            ptr = (char*)"symbolic link";
        else if (S_ISSOCK(buf.st_mode))
            ptr = (char*)"socket";
        else
            ptr = (char*)"unknow mode";
        
        printf("%s\n", ptr);
    }

    exit(0);
}

/*
 * $: gcc -g err.c lstat.c
 * $: ./a.out /etc/passwd /etc /dev/log /dev/tty
 *  err.c: regular
 * */
