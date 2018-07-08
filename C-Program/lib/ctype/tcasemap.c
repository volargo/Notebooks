/*
 * =====================================================================================
 *
 *       Filename:  tcasemap.c
 *
 *    Description:  测试大小写映射函数
 *
 *        Version:  1.0
 *        Created:  07/31/2017 02:38:31 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (imau), wood@khan.ren
 *   Organization:  zy.imau.edu.cn
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char *p;

    if (argc != 2) {
        fprintf(stderr, "usage: command string\n");
        exit(EXIT_FAILURE);
    }

    p = argv[1];
    while (*p != '\0'){
        printf("tolower('%c') is '%c'; ", *p, tolower(*p));
        printf("toupper('%c') is '%c';\n", *p, toupper(*p));
        p++;
    }

    return 0;
}
