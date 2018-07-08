/*
 * =====================================================================================
 *
 *       Filename:  echo.c
 *
 *    Description:　创建较长长度的宏定义
 *
 *        Version:  1.0
 *        Created:  07/11/2017 07:36:21 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (LF), wood@khan.ren
 *   Organization:  imau
 *
 * =====================================================================================
 */
#include <stdio.h>

#define LENGTH 50

#ifndef ECHO
#define ECHO(s) (fgets(s, LENGTH, stdin), printf("%s", s))
#endif

int main(void)
{
    char str[50];

    ECHO(str);

    return 0;
}
