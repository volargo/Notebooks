/*
 * =====================================================================================
 *
 *       Filename:  copyfile.c
 *
 *    Description:  use read and write function to copy
 *
 *        Version:  1.0
 *        Created:  03/23/2018 02:24:11 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Long-Fei (), wood@khan.ren
 *   Organization:  www.khan.ren/wiki
 *
 * =====================================================================================
 */

#include "apue.h"

#define BUFSIZE 4096

int
main(void)
{
    int     len;
    char    buf[BUFSIZE];

    printf("Press <Ctrl+D> quit\n");
    while ((len = read(STDIN_FILENO, buf, BUFSIZE)) > 0) {
        if (write(STDOUT_FILENO, buf, len) != len) {
            err_sys("write error");
        }
    }

    if (len < 0) {
        err_sys("read error");
    }

    exit(0);
}

/*
 * #: gcc err.c copyfile.c -o copyfile
 * #: ./copyfile
 */
