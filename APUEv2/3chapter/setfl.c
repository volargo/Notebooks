/*
 * =====================================================================================
 *
 *       Filename:  setfl.c
 *
 *    Description:  set one or more file's status flags
 *
 *        Version:  1.0
 *        Created:  03/23/2018 06:59:24 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Long-Fei (), wood@khan.ren
 *   Organization:  www.khan.ren/wiki
 *
 * =====================================================================================
 */
#include "apue.h"
#include <fcntl.h>

void
set_fl(int fd, int flags)   /* flags are file status flags to turn on */
{
    int     val;

    if ((val = fcntl(fd, F_GETFL, 0)) < 0) {
        err_sys("fcntl F_GETFL error");
    }

    val |= flags;           /* turn on flags */

    if (fcntl(fd, F_SETFL, val) < 0) {
        err_sys("fcntl F_SETFL error");
    }
}
