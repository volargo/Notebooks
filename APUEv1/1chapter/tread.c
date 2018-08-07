/*
 * =====================================================================================
 *
 *       Filename:  tread.c
 *
 *    Description:  use 'read' function reading data from file
 *
 *        Version:  1.0
 *        Created:  08/11/2017 09:51:36 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (imau), wood@khan.ren
 *   Organization:  zy.imau.edu.cn
 *
 * =====================================================================================
 */
#include "apue.h"
#include <fcntl.h>      /* include O_RDONLY and O_EXCL */
#include <limits.h>     /* include SSIZE_MAX */
#include <unistd.h>     /* include 'read' function */

#define MAXLINE 4096

int
main(int argc, char *argv[])
{
    int         fd, len = 0, ch;
    char        buf[MAXLINE];
    FILE        *fp;

    if (argc != 2) {
        err_sys("usage: command filename");
    }

    /* test file open or not */
    if ((fp = fopen(argv[1], "rb+")) == NULL) {
        err_sys("can't open %s", argv[1]);
    }

    /* can be open file or not */
    if ((fd = open(argv[1], O_RDONLY)) == -1) {
        err_sys("can't open %s", argv[1]);
    }

    /* get file content size */
    while ((ch = getc(fp)) != EOF) {
        len++;
    }

    /* specify file length and read it */
    if (read(fd, buf, sizeof(char)*len) == -1) {
        err_sys("can't read %s", argv[1]);
    } else {
        printf("file content:\n%s\n", buf);
    }
    
    exit(0);
}
