/*
 * =====================================================================================
 *
 *       Filename:  fclose.c
 *
 *    Description:  fclose()函数: 关闭文件
 *
 *        Version:  1.0
 *        Created:  07/23/2017 12:56:50 PM
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

    fp = fopen(FILE_NAME, "r+");
    if (fp != NULL) {
        printf("can open.\n");
    }

    // fclose(FILE *stream);
    fclose(fp);

    return 0;
}
