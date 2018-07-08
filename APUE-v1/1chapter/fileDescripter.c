/*
 * =====================================================================================
 *
 *       Filename:  file_descript.c
 *
 *    Description:  确定文件描述符数量
 *
 *        Version:  1.0
 *        Created:  08/08/2017 07:25:19 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (imau), wood@khan.ren
 *   Organization:  zy.imau.edu.cn
 *
 * =====================================================================================
 */
#include "apue.h"
#include <errno.h>
#include <limits.h>

#ifdef OPEN_MAX
static long openmax = OPEN_MAX;
#else
static long openmax = 0;
#endif

/*
 * If OPEN_MAX is indeterminate, we're not guaranted that this is adequate
 */
#define OPEN_MAX_GUESS  256

long
open_max(void) {
    if (openmax == 0) {     /* first time through */
        errno = 0;
        if ((openmax = sysconf(_SC_OPEN_MAX)) < 0) {
            if (errno == 0) {
                openmax = OPEN_MAX_GUESS;       /* it's indeterminate */
            } else {
                err_sys("sysconf error for _SC_OPEN_MAX");
            }
        }
    }

    return (openmax);
}
