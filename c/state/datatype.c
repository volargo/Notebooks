/*
 * =====================================================================================
 *
 *       Filename:  datatype.c
 *
 *    Description:  存储类型总结
 *
 *        Version:  1.0
 *        Created:  06/03/2017 05:55:04 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (LF), wood@khan.ren
 *   Organization:  imau
 *
 * =====================================================================================
 */
#include <stdio.h>

int a;              // 存储期限:静态; 作用域:文件; 链接:外部
extern int b;       // 存储期限:静态; 作用域:文件; 链接:
static int c;       // 存储期限:静态; 作用域:文件; 链接:内部

void f(int d, register int a)   // 存储期限:自动; 作用域:块; 链接:无
{
    auto int g;     // 存储期限:自动; 作用域:块; 链接:无
    int h;          // 存储期限:自动; 作用域:块; 链接:无
    static int i;   // 存储期限:静态; 作用域:筷; 链接:无
    extern int j;   // 存储期限:静态; 作用域:块; 链接:
    register int k  // 存储期限:自动; 作用域:块; 链接:无
;
}
