/*
 * =====================================================================================
 *
 *       Filename:  p7.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/29/2017 12:05:57 PM
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
    int i, j, n;
    float x;

    n = scanf("%d%f%d", &i, &x, &j);

    fprintf(stdout, "i = %d\nx = %f\nj = %d\nn = %d\n", i, x, j, n);

    return 0;
}
