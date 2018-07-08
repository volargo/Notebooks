/*
 * =====================================================================================
 *
 *       Filename:  test.c
 *
 *    Description:  位移运算符
 *
 *        Version:  1.0
 *        Created:  07/20/2017 03:29:10 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (LF), wood@khan.ren
 *   Organization:  imau
 *
 * =====================================================================================
 */
#include <stdio.h>

#define ECHO(n) (printf("%ld\n", n))

int main(void)
{
    unsigned long int i = 13, j, k;

    // 不改变操作数
    j = i << 2; ECHO(j);
    j = i >> 2; ECHO(j);

    // 改变操作数
    i <<= 2; ECHO(i);
    i >>= 2; ECHO(i);

    i = 21;
    j = 56;
    k = ~i;     ECHO(k);    // 按位取反, 一元运算
    k = i&j;    ECHO(k);    // 按位与, 二元运算
    k = i^j;    ECHO(k);    // 按位异或, 二元运算
    k = i|j;    ECHO(k);    // 按位或, 二元运算

    return 0;
}
