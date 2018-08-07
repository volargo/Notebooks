/*
 * =====================================================================================
 *
 *       Filename:  memset.c
 *
 *    Description:  将一个字符的多个副本存储到指定的内存区域
 *
 *        Version:  1.0
 *        Created:  08/02/2017 10:05:06 PM
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

int main(void)
{
    char a[10];

    memset(a, 0, sizeof(a));
    fprintf(stdout, "%s\n", a);

    return EXIT_SUCCESS;
}
