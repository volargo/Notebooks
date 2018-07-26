/*
 * =====================================================================================
 *
 *       Filename:  fgets2fputs.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  08/20/2017 11:30:55 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (Loong), urloong@163.com
 *   Organization:  zy.imau.edu.cn
 *
 * =====================================================================================
 */
#include "apue.h"

int
main(void)
{
    char    buf[MAXLINE];

    while (fgets(buf, MAXLINE, stdin) != NULL) {
        if (fputs(buf, stdout) == EOF) {
            err_sys("fgets2fputs.c:27: fputs error");
        }
    }
    if (ferror(stdin)) {
        err_sys("stdin error");
    }

    exit(0);
}

