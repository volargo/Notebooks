/*
 * =====================================================================================
 *
 *       Filename:  open_close.c
 *
 *    Description:  测试fopen和fclose函数
 *
 *        Version:  1.0
 *        Created:  07/22/2017 08:50:07 PM
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

#define FILE_NAME "example.dat"

int main(void)
{
    FILE *fp;

    if ((fp = fopen(FILE_NAME, "r")) == NULL) {
        printf("Can't open %s\n", FILE_NAME);
        exit(EXIT_FAILURE);
    }

    // fclose函数成功关闭文件则返回0值, 否则返回错误代码EOF(stdio.h中定义的宏)
    if (!fclose(fp)) {
        puts("Close file success...");
    }

    return 0;

}
