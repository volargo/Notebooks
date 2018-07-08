/*
 * =====================================================================================
 *
 *       Filename:  p16.c
 *
 *    Description:  这道题有问题.
 *
 *        Version:  1.0
 *        Created:  07/30/2017 11:50:16 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (imau), wood@khan.ren
 *   Organization:  zy.imau.edu.cn
 *
 * =====================================================================================
 */
#include <stdio.h>

int main(void)
{
    char str[20], sales_rank[20];

    fgets(str, sizeof(str), stdin);
    sscanf(str, "%[0123456789,]", sales_rank);
    printf("%s\n", sales_rank);

    return 0;
}
