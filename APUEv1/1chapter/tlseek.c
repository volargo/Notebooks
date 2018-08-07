/*
 * =====================================================================================
 *
 *       Filename:  tlseek.c
 *
 *    Description:  create an empty file
 *
 *        Version:  1.0
 *        Created:  08/10/2017 22:35:13 PM
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
/*
 * 'apue.h' has these library, if not you need add flowing 'include'
 */
#ifndef _APUE_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#endif  /* _APUE_H */

int
main(void)
{
    int     fd;
    char buf1[] = "hola,sunflower girl.";
    char buf2[] = "ABCDEFGHIJ";

    if ((fd = creat("file.hole", FILE_MODE)) < 0)
        err_sys("can't create file");

    if (write(fd, buf1, strlen(buf1)) != (int)strlen(buf1))
        err_sys("buf1 write error");
    /* offset now is 20 */

    if (lseek(fd, 16384, SEEK_SET) == -1)
        err_sys("lseek error");
    /* offset now = 16384 */

    if (write(fd, buf2, strlen(buf2)) != 10)
        err_sys("buf2 write error");
    /* offset now = 16394 */

    exit(0);
}

// Test way:
/* ----------------------------------------------------
 * $: ./a.out
 * $: ls -l hole.file
 *    # you need look size information
 * $: sudo od -c hole.file
 *    # different size information
 * ----------------------------------------------------*/
