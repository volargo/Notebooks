/*
 * =====================================================================================
 *
 *       Filename:  write.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/23/2018 01:42:50 PM
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
    // right arguments or not
    if (argc != 2) {
        err_msg("too few arguments");
    }

    // read datas from standard input
    char    buf[BUFSIZE];
    if ((read(STDIN_FILENO, buf, BUFSIZE)) == -1) {
        err_exit(EXIT_FAILURE, "read error");
    }
    
    // open the file
    int     fd;
    if ((fd = open(argv[1], O_RDWR | O_CREAT | O_EXCL, 0640)) == -1) {
        err_exit(EXIT_FAILURE, "open error");
    }

    // write datas to the file
    if (write(fd, buf, 5) != 5) {
        err_exit(EXIT_FAILURE, "write error");
    }

    // close the file
    close(fd);

    exit(EXIT_SUCCESS);
}

/*
 * $: gcc -g err.c write.c -o write
 * $: ./write <filename>
 *    input
 * */
