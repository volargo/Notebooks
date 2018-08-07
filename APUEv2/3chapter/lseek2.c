/*
 * =====================================================================================
 *
 *       Filename:  lseek3_1.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/22/2018 08:38:05 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Long-Fei (), wood@khan.ren
 *   Organization:  www.khan.ren/wiki
 *
 * =====================================================================================
 */

#include "apue.h"

int main(void)
{
    /*
     * because the offset may be negative, so compare lseek return values,
     * don't test it is less than zero, and to test whether it is equal to -1
     */
    if (lseek(STDIN_FILENO, 0, SEEK_CUR) == -1) {
        perror("lseek error");
        exit(EXIT_FAILURE);
    } else {
        printf("seek OK\n");
    }

    exit(EXIT_SUCCESS);
}

/*
 * <usage>:
 * $: gcc -g lseek2.c
 * $: ./a.out < /etc/passwd
 *  seek OK
 * $: cat < /etc/passwd | ./a.out
 *  cannot seek
 * $: ./a.out < /var/spool/cron/FIFO
 *  cannot seek
 * */
