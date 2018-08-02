/*
 * =====================================================================================
 *
 *       Filename:  scanf.c
 *
 *    Description:  scanf()和fscanf()函数
 *
 *        Version:  1.0
 *        Created:  07/23/2017 04:30:55 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (LF), wood@khan.ren
 *   Organization:  imau
 *
 * =====================================================================================
 */
#include <stdio.h>

int main(void)
{
    int i, j;

    fputs("Please enter value: ", stdout);
    fscanf(stdin, "%d%d", &i, &j);
    fprintf(stdout, "Print input value: %d, %d\n", i, j);

    return 0;
}
