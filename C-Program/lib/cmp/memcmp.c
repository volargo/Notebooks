/*
 * =====================================================================================
 *
 *       Filename:  memcmp.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/31/2017 09:35:12 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (imau), wood@khan.ren
 *   Organization:  zy.imau.edu.cn
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    size_t len;

    if (argc != 4) {
        fprintf(stderr, "usage: command way\n");
        exit(EXIT_FAILURE);
    }

    // strncmp 和 strcmp 大同小异, 懒得写例子了.
    sscanf(argv[3], "%ld", &len);
    if (memcmp(argv[1], argv[2], len) == 0) {
        printf("str1 equal str2\n");
    } else {
        printf("str1 not equal str2\n");
    }

    return EXIT_SUCCESS;
}
