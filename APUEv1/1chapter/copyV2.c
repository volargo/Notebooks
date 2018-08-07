/*
 * =====================================================================================
 *
 *       Filename:  fcopy.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/07/2017 11:07:59 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (imau), wood@khan.ren
 *   Organization:  zy.imau.edu.cn
 *
 * =====================================================================================
 */
#include "apue.h"

#define BUFFSIZE 4096

int
main(void)
{
    int     n;
    char    buf[BUFFSIZE];

    while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0) {
        if (write(STDOUT_FILENO, buf, n) != n) {
            err_sys("write error");
        }
    }
    if (n < 0) {
        err_sys("read error");
    }

    exit(0);
}
