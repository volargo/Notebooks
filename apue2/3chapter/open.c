/*
 * =====================================================================================
 *
 *       Filename:  open.c
 *
 *    Description:  open and openat 
 *
 *        Version:  1.0
 *        Created:  03/22/2018 09:03:49 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
    int  fd;

    if ((fd = open("./openfile", O_RDWR | O_CREAT, 0660)) < 0) {
        perror("open error ");
        exit(EXIT_FAILURE);
    } else {
        printf("open successed ...\n");
    }

    if ((fd = openat(AT_FDCWD, "./openatfile", O_RDWR | O_CREAT, 0660)) < 0) {
        perror("openat error ");
        exit(EXIT_FAILURE);
    } else {
        printf("openat successed ...\n");
    }

    close(fd);

    exit(0);
}
