/*
 * =====================================================================================
 *
 *       Filename:  tfopen.c
 *
 *    Description:  test tfopen function
 *
 *        Version:  1.0
 *        Created:  08/19/2017 06:24:23 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (Loong), urloong@163.com
 *   Organization:  zy.imau.edu.cn
 *
 * =====================================================================================
 */
#include "apue.h"
#include <wchar.h>

int
main(int argc, char *argv[])
{
    int     i;
    FILE    *fp;

    if (argc < 2) {
        err_ret("usage: command stream ...");
    }
    for (i = 1; i < argc; i++) {
        if ((fp = fopen(argv[i], "rb+")) == NULL) {
            fprintf(stderr, "no such file or directory.\n");
            continue;
        }
        printf("open %s successed\n", argv[i]);
    }

    exit(0);
}
