/*
 * =====================================================================================
 *
 *       Filename:  freopen.c
 *
 *    Description:  freopen()函数: 为打开的流附加文件
 *
 *        Version:  1.0
 *        Created:  07/23/2017 12:59:27 PM
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
    FILE *fp1 = fopen(FILE_NAME, "r+");

    // freopen(const char * restrict filename, const char * restrict mode, FILE * restrict stream);
    FILE *fp2 = freopen("fclose.c", "r", stdout);

    fclose(fp1);
    fclose(fp2);

    return 0;
}
