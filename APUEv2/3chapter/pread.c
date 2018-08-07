/*
 * =====================================================================================
 *
 *       Filename:  pread.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/23/2018 02:49:33 PM
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
    if (argc == 1) { 
        err_sys("too few arguments");
    }
    else if (argc == 2) {
        int     fd;                 // file descriptions
        char    buf[BUFSIZE];       // buffer
        off_t   currpos = 0;        // offset
        ssize_t len;                // number of read bytes

        // open file
        if ((fd = open(argv[1], O_RDONLY)) == -1) {
            err_sys("open FILE error");
        }

        // read data from the file
        if ((len = pread(fd, buf, BUFSIZE, currpos)) == -1) {
            err_sys("pread file error");
        }

        // let the file datas write to the screen
        if (write(STDOUT_FILENO, buf, len) != len) {
            err_sys("write error");
        }

        // close the file
        close(fd);
    }
    else {
        err_msg("too many arguments");
    }

    exit(0);
}

/*
 * #: gcc -g err.c pread.c -o pread
 * #: ./pread <filename>
 */
