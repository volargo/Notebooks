/*
 * =====================================================================================
 *
 *       Filename:  tchdir.c
 *
 *    Description:  test chdir function(hasn't changed works-dir)
 *
 *        Version:  1.0
 *        Created:  08/19/2017 09:27:31 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (Loong), urloong@163.com
 *   Organization:  zy.imau.edu.cn
 *
 * =====================================================================================
 */
#include "apue.h"
#include <unistd.h>

int
main(int argc, char *argv[])
{
    if (argc != 2) {
        err_ret("usage: command path");
    }

    if (chdir(argv[1]) < 0) {
        err_sys("chdir error for %s", argv[1]);
    }

    exit(0);
}
