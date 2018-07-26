/*
 * =====================================================================================
 *
 *       Filename:  get_fl.c
 *
 *    Description:  specify file-description and print file status flag.
 *
 *        Version:  1.0
 *        Created:  08/12/2017 03:59:36 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (Loong), urloong@163.com
 *   Organization:  zy.imau.edu.cn
 *
 * =====================================================================================
 */
#include "apue.h"
#include <fcntl.h>

int
main(int argc, char *argv[])
{
    int     val;

    // check command argument numbers right or no
    if (argc != 2) {
        err_sys("usage: command <description#>");
    }

    /*
     * atoi, convert a string to an integer
     * fcntl, manipulate file descriptor. The operation is determined by cmd(the 'val')
     */
    if ((val = fcntl(atoi(argv[1]), F_GETFL, 0)) < 0) {
        err_sys("fcntl error for fd %d", atoi(argv[1]));
    }

    /*
     * first, you need use 'O_ACCMODE' get access mode
     */
    switch(val & O_ACCMODE) {
        case O_RDONLY:      // old SVR-version support set 0 replace
            printf("read only");
            break;
        case O_WRONLY:      // old SVR-version support set 1 replace
            printf("write only");
            break;
        case O_RDWR:        // old SVR-version support set 2 replace
            printf("read write");
            break;
        default:
            err_dump("unknow access mode");
    }

    if (val & O_APPEND)         /* file status flag: O_APPEND */
        printf(", append");
    if (val & O_NONBLOCK)       /* file status flag: O_NONBLOCK */
        printf(", nonblocking");
#if defined(O_SYNC)
    if (val & O_SYNC)
        printf(", synchronous writes");
#endif

/*
 * Only FreeBSD and Mac OS X support
 * Test not defined file access mode by '_POSIX_C_SOURCE' power
 */
#if !defined(_POSIX_C_SOURCE) && defined(O_FSYNC)
    if (val & O_FSYNC)
        printf(", synchronous writes");
    if (val & O_ASYNC)
        ;       // Sorry. gay, I don't write these test code
#endif

    putchar('\n');
    exit(0);
}

/* Test way:
 * ---------------------------------------------------------------------
 *  eg1 $: ./a.out 0 < /dev/tty
 *        read only
 *  eg2 $: ./a.out 1 > temp.foo
 *      $: less temp.foo
 *        write only
 *  eg3 $: ./a.out 2 2 >> temp.foo
 *        write only, append
 *  eg4 $: ./a.out 5 5 <> temp.foo
 *        read write
 * ----------------------------------------------------------------------*/
