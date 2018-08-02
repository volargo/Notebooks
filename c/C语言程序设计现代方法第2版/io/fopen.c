/*
 * =====================================================================================
 *
 *       Filename:  fopen.c
 *
 *    Description:  fopen()函数: 打开文件
 *
 *        Version:  1.0
 *        Created:  07/23/2017 12:52:34 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (LF), wood@khan.ren
 *   Organization:  imau
 *
 * =====================================================================================
 */
#include <stdio.h>

#define FILE_NAME "example.dat"

int main(void)
{
    FILE *fp;

    // fopen(const char * restrict name, const char * restrict mode);
    fp = fopen(FILE_NAME, "r");

    return 0;
}
