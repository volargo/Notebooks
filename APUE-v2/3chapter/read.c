/*
 * =====================================================================================
 *
 *       Filename:  read.c
 *
 *    Description:  read data from opened file
 *
 *        Version:  1.0
 *        Created:  03/23/2018 11:08:09 AM
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

int main(int argc, char *argv[])
{
    /*
     * two arguments or not, and return error Msg
     */
    if (argc != 2) {
        err_msg("too few arguments");
        exit(EXIT_SUCCESS);
    }

    /*
     * open file and get 'fd' value
     */
    int    fd;
    if ((fd = open(argv[1], O_RDONLY, 0640)) == -1) {
        err_sys("open file error");
    }

    /*
     * bytes read from a file
     */
    ssize_t r_data_len;
    char    buf[BUFSIZE];
    if ((r_data_len = read(fd, buf, BUFSIZE)) == -1) {
        err_ret("read file error");
    }

    // printf number of bytes read
    printf("Number of bytes read is: %ld\n", r_data_len);

    close(fd);

    exit(EXIT_SUCCESS);
}

/*
 * $: gcc -o read read.c err.c
 * $: ./read <filename>
 */
