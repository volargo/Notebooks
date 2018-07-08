/*
 * =====================================================================================
 *
 *       Filename:  eg1.c
 *
 *    Description:  带有存储类型和三个生命副的声明
 *
 *        Version:  1.0
 *        Created:  05/31/2017 08:44:06 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (LF), wood@khan.ren
 *   Organization:  imau
 *
 * =====================================================================================
 */
#include <stdio.h>

extern int square(int);     // extern: 存储类型; int: 类型说明符; square: 声明符

int main(void)
{
    // 类型限定符和类型说明符必须跟随在存储类型的后面
#if 0
    存储类型: auto, static, extern, register
    类型限定符: const, volatile
    类型说明符: void, char, short, int, long, float...
#endif

    static float x, y, *p;  // static: 存储类型; (x, y, *p): 声明符

    const char month[] = "January";     // const: 类型限定符; char: 类型说明符; month: 声明符

    extern const unsigned long int a[10];   // extern: 存储类型; const: 类型限定符; unsigned long int: 类型说明符; a[10]: 说明符

    return 0;
}
