/*
 * =====================================================================================
 *
 *       Filename:  toffset.c
 *
 *    Description:  test current file offset
 *
 *        Version:  1.0
 *        Created:  08/10/2017 08:26:14 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (imau), wood@khan.ren
 *   Organization:  zy.imau.edu.cn
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int
main(void)
{
    // test eg1 $: ./a.out < /etc/motd
    // test eg2 $: cat /etc/motd | ./a.out
    // test eg3 $: ./a.out < /var/spool/cron/FIFO
    if (lseek(STDIN_FILENO, 0, SEEK_CUR) == -1) {
        printf("can't seek\n");
    } else {
        printf("seek OK\n");
    }

    exit(0);
}
