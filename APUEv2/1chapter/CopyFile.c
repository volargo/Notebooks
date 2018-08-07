/*
 * =====================================================================================
 *
 *       Filename:  CopyFile.c
 *
 *    Description:  从标准输入读,并向标准输出写.
 *
 *        Version:  1.0
 *        Created:  11/30/2017 01:53:48 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (Loong), urloong@163.com
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
