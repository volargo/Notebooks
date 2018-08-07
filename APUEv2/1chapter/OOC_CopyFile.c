/*
 * =====================================================================================
 *
 *       Filename:  OOC_CopyFile.c
 *
 *    Description:  OOC of CopyFile
 *
 *        Version:  1.0
 *        Created:  11/30/2017 02:06:33 PM
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

void *CopyFile() {
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

    return NULL;
}

int
main(void)
{
    void *(*pf)(void);

    pf = &CopyFile;

    (*pf)();

    exit(0);
}
