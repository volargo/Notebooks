/*
 * =====================================================================================
 *
 *       Filename:  fcntl.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/23/2018 06:22:04 PM
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

int
main(int argc, char *argv[])
{
    int     val;

    if (argc != 2) {
        err_quit("usage: a.out <descriptor#>");
    }

    if ((val = fcntl(atoi(argv[1]), F_GETFL, 0)) < 0) {
        err_sys("fcntl error for fd %d", atoi(argv[1]));
    }

    // get access mode for the file flag
    switch (val & O_ACCMODE) {
        case O_RDONLY:
            printf("read only");
            break;
        case O_WRONLY:
            printf("write only");
            break;
        case O_RDWR:
            printf("read write");
            break;
        case O_EXCL:
            printf("excl");
            break;
        default:
            err_dump("unkonw access mode");
    }

    //  get file's O_APPEND flag
    if (val & O_APPEND) {
        printf(", append");
    }
    // get file's O_NONBLOCK flag
    if (val & O_NONBLOCK) {
        printf(", nonblocking");
    }
    // get file's O_SYNC flag
    if (val & O_SYNC) {
        printf(", synchronoous writes");
    }

#if !defined(_POSIX_C_SOURCE) && defined(O_FSYNC) && (O_FSYNC != O_SYNC)
    if (val & O_FSYNC)
        printf(", synchronous writes")
#endif

    putchar('\n');
    exit(0);
}

/*
 * <usage>:
 * $: gcc -g err.c fcntl.c
 * $: ./a.out 0 < /dev/tty
 *  read only
 * $: ./a.out 1 > temp.foo
 * $: cat temp.foo
 *  write only
 * $: ./a.out 2 2>> temp.foo
 *  write only, append
 * $: ./a.out 5 5<> temp.foo
 *  read write
 */
