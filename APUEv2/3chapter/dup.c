/*
 * =====================================================================================
 *
 *       Filename:  dup.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/23/2018 04:34:14 PM
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

#define BUFSIZE 4096

int
main(int argc, char *argv[])
{
    if (argc != 2) {
        err_quit("too few arguments");
    }

    int     fd;
    if ((fd = open(argv[1], O_RDWR)) == -1) {
        err_sys("open error");
    }

    // copy file descripter
    int     newfd;
    char    buf[BUFSIZE];
    ssize_t read_len;

    newfd = dup(fd);
    if ((read_len = pread(newfd, buf, BUFSIZE, 0)) == -1) {
        err_sys("pread error");
    }
    printf("Number of bytes read is: %ld\n", read_len);

    close(fd);
    close(newfd);

    exit(0);
}
