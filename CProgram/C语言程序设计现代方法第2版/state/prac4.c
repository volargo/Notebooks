/*
 * =====================================================================================
 *
 *       Filename:  prac4.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/13/2017 10:11:08 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (LF), wood@khan.ren
 *   Organization:  imau
 *
 * =====================================================================================
 */
#include <stdio.h>

int f1(int i) {
    static int j_1 = 0;
    return i * j_1++;
}

int f2(int i) {
    static int j_2 = 0;
    return i * j_2++;
}
int main(void)
{
    printf("%d\n", f2(10));     // 之前函数f2未被调用

    // 之前函数f1被调用过５次
    for (int x = 0; x < 5; x++) {
        printf("%d\n", f1(10));
    }
    printf("%d\n", f1(10));

    return 0;
}
