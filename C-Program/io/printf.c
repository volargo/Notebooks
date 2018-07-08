/*
 * =====================================================================================
 *
 *       Filename:  printf.c
 *
 *    Description:  printf()函数
 *
 *        Version:  1.0
 *        Created:  07/23/2017 02:37:22 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (LF), wood@khan.ren
 *   Organization:  imau
 *
 * =====================================================================================
 */
#include <stdio.h>

union Print_Type {
    unsigned int a;
    unsigned long b;
    unsigned char c;
    float d;
    double e;
} Type;

int main(void)
{
    Type.a = 10;
    printf("%5.5d\n", Type.a);

    Type.d = 0.01f;
    printf("%.5F\n", Type.d);

    return 0;
}
