/*
 * =====================================================================================
 *
 *       Filename:  getc2putc.c
 *
 *    Description:  let getc copy to putc
 *
 *        Version:  1.0
 *        Created:  08/20/2017 11:25:34 AM
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
    int     ch;

    while ((ch = getc(stdin)) != EOF) {
        if (putc(ch, stdout) == EOF) {
            err_sys("output error");
        }
    }

    if (ferror(stdin)) {
        err_sys("input error");
    }
    exit(0);
}
