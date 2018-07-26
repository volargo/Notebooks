/*
 * =====================================================================================
 *
 *       Filename:  topen.c
 *
 *    Description:  test 'open' function
 *
 *        Version:  1.0
 *        Created:  08/09/2017 09:06:09 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (imau), wood@khan.ren
 *   Organization:  zy.imau.edu.cn
 *
 * =====================================================================================
 */
#include "apue.h"
#include <fcntl.h>

int
main(void)
{
    char    *str = "data.dat";

    // int open(const char *pathname, int oflag, ... /* mode_t mode */);
    if (open(str, O_RDWR) == (-1)) {     /* error return -1 or else return a positive number */
        err_sys("can't open path");
    } else {
        printf("open path successful.\n");
    }

    return 0;
}
