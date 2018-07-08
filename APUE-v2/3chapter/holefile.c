/*
 * =====================================================================================
 *
 *       Filename:  hole.c
 *
 *    Description:  create an empty file
 *
 *        Version:  1.0
 *        Created:  03/22/2018 09:06:59 PM
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

char    buf1[] = "abcdefghij";
char    buf2[] = "ABCDEFGHIJ";

int
main(void)
{
    int     fd;
    mode_t  mod = 0660;

    // create a file
    if ((fd = creat("file.hole", mod)) < 0) {
        err_sys("creat error");
    }

    // write data to the file
    if (write(fd, buf1, 10) != 10) {
        err_sys("buf1 write error");
    }

    // set offset of the file
    if (lseek(fd, 16384, SEEK_SET) == -1) {
        err_sys("lseek error");
    }

    // append data to the file
    if (write(fd, buf2, 10) != 10) {
        err_sys("buf2 write error");
    }

    exit(0);
}

/*
 * $: gcc -g holefile.c -o holefile
 * $: ./holefile 
 * od -c file.hole
 */
