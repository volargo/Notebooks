/*
 * =====================================================================================
 *
 *       Filename:  trename.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/17/2017 10:26:43 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (Loong), urloong@163.com
 *   Organization:  zy.imau.edu.cn
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>

int
main(int argc, char *argv[])
{
    if (argc != 3) {
        fprintf(stderr, "usage: command oldname newname\n");
        exit(EXIT_FAILURE);
    }

    if (rename(argv[1], argv[2]) != 0) {
        fprintf(stderr, "rename error\n");
        exit(EXIT_FAILURE);
    }

    exit(0);
}
