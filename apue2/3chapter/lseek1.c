/*
 * =====================================================================================
 *
 *       Filename:  lseek.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/22/2018 05:53:58 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Long-Fei (), wood@khan.ren
 *   Organization:  www.khan.ren/wiki
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("Too few arguments\n");
        exit(0);
    }

    /* 
     * open test file
     */
    int     fd;
    if ((fd = open(argv[1], O_RDWR | O_APPEND, 0660)) < 0) {
        perror("open error");
        exit(EXIT_FAILURE);
    }
    write(fd, "Hello", 5);   // write data
    
    /*
     * view offset of test file
     */
    off_t   offset = 10;
    off_t   currpos;
    if ((currpos = lseek(fd, offset, SEEK_END)) < 0) {
        perror("lseek error ...\n");
        exit(EXIT_FAILURE);
    } else {
        printf("offset is %ld, lseek successed ...\n", currpos);
    }

    close(fd);

    exit(EXIT_SUCCESS);
}

/*
 * $: gcc -g lseek.c -o lseek
 * $: touch tfile
 * $: ./lseek tfile
 */
