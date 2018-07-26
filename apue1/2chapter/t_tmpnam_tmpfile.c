/*
 * =====================================================================================
 *
 *       Filename:  t_tmpnam_tmpfile.c
 *
 *    Description:  test tmpnam and tmpfile function from <stdio.h>
 *
 *        Version:  1.0
 *        Created:  08/20/2017 08:57:59 PM
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
#include <stdarg.h>
#include <errno.h>
#include <stdlib.h>

#define MAXLINE 4096

static void err_doit(int, int, const char *, va_list);
void err_sys(int, const char *, ...);

int
main(void)
{
    char    name[L_tmpnam], line[MAXLINE];
    FILE    *fp;

    // use tmpnam was dangers, better use mkstemp from <stdlib.h>
    printf("%s\n", tmpnam(NULL));       /* first temp name */
    tmpnam(name);                       /* second temp name */
    printf("%s\n", name);

    if ((fp = tmpfile()) == NULL) {     /* creat temp file */
        err_sys(EBADF, "tmpfile error:41:");
    }
    fputs("one line of output\n", fp);  /* write to temp file */
    rewind(fp);                         /* then read it back */
    if (fgets(line, sizeof(line), fp) == NULL) {
        err_sys(ENOSR, "fgets error:46:");
    }
    fputs(line, stdout);            /* print the line we wrote  */

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
err_sys(int error, const char *fmt, ...) {
    va_list     ap;

    va_start(ap, fmt);
    err_doit(1, error, fmt, ap);
    va_end(ap);
}
