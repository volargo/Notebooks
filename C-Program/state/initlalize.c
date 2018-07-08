/*
 * =====================================================================================
 *
 *       Filename:  initialize.c
 *
 *    Description:  初始化式
 *
 *        Version:  1.0
 *        Created:  07/11/2017 04:46:50 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (LF), wood@khan.ren
 *   Organization:  imau
 *
 * =====================================================================================
 */
#include <stdio.h>

#define FIRST 1
#define LAST 100

void test(void) {
    static int i = LAST - FIRST + 1;
    printf("%d\n", i);
}

int main(void)
{
    test();

    return 0;
}
