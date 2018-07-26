/*
 * =====================================================================================
 *
 *       Filename:  register.c
 *
 *    Description:  register存储类型,要求编译器将变量存储在寄存器中
 *
 *        Version:  1.0
 *        Created:  06/03/2017 05:08:03 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (LF), wood@khan.ren
 *   Organization:  imau
 *
 * =====================================================================================
 */
#include <stdio.h>

int sum_array(int a[], int n) {
    register int i;
    int sum = 0;

    for (i = 0; i < n; i++) {
        sum += a[i];
    }
    return sum;
}
