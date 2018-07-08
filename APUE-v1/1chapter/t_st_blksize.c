/*
 * =====================================================================================
 *
 *       Filename:  test st_blksize default length
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/15/2017 08:09:51 PM
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
#include <sys/stat.h>

int
main(void)
{
    struct stat     bufstat;
    char *filename = "foo";

    if (stat(filename, &bufstat) < 0) {
        fprintf(stderr, "stat error for %s", filename);
        exit(EXIT_FAILURE);
    }
    printf("%ld\n", bufstat.st_blksize);
    printf("%ld\n", bufstat.st_blocks);

    exit(0);
}
