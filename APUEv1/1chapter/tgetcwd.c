/*
 * =====================================================================================
 *
 *       Filename:  tgetcwd.c
 *
 *    Description:  test chdir and getcwd function from <unistd.h>
 *
 *        Version:  1.0
 *        Created:  08/19/2017 09:48:01 AM
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
    char    *ptr;
    int     size;

    if (argc != 2) {
        err_msg("usage: command dir");
    }

    if (chdir(argv[1]) < 0) {
        err_sys("chdir failed");
    }

    ptr = path_alloc(&size);
    if (getcwd(ptr, size) == NULL) {
        err_sys("getcwd failed");
    }

    printf("cwd = %s\n", ptr);
    exit(0);
}
