/*
 * =====================================================================================
 *
 *       Filename:  twrite.c
 *
 *    Description:  test 'write' function
 *
 *        Version:  1.0
 *        Created:  08/11/2017 10:46:53 AM
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
#include <sys/types.h>
#include <unistd.h>

int
main(int argc, char *argv[])
{
    int         fd;

    if (argc != 3) {
        err_quit("usage: command filename content");
    }

    /* 
     * check file can open or not,
     * if hasn't file then create new file,
     * new content files written in supplementary manner
     */
    if ((fd = open(argv[1], O_RDWR | O_CREAT | O_EXCL | O_APPEND)) == -1) {
        err_sys("can't open %s", argv[1]);
    }

    if (write(fd, argv[2], sizeof(argv[2])*sizeof(char)) == -1) {
        err_sys("write error");
    } else {
        printf("append successful\n");
    }

    exit(0);
}
