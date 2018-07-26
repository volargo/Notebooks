/*
 * =====================================================================================
 *
 *       Filename:  extern.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/11/2017 01:49:47 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (LF), wood@khan.ren
 *   Organization:  imau
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    extern int a[];     // 数组存储类型为extern时,放括号可以为空

    return 0;
}
