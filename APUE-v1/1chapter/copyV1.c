/*
 * =====================================================================================
 *
 *       Filename:  v1copy.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/07/2017 08:12:21 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (imau), wood@khan.ren
 *   Organization:  zy.imau.edu.cn
 *
 * =====================================================================================
 */
#include "apue.h"

int main(void)
{
    int     c;

    while ((c = getc(stdin)) != EOF) {
        if (putc(c, stdout) == EOF) {
            err_sys("output error");
        }
    }
    if (ferror(stdin)) {
        err_sys("output error");
    }

    exit(0);
}
