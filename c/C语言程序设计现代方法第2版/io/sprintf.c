/*
 * =====================================================================================
 *
 *       Filename:  sprintf.c
 *
 *    Description:  字符串的输入/输出 sprintf()函数
 *
 *        Version:  1.0
 *        Created:  07/28/2017 09:25:45 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (imau), wood@khan.ren
 *   Organization:  zy.imau.edu.cn
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char str[10];

    // int sprintf(char *restrict s, const char *restrict format, ...);
    // sprintf将读取的数字也当做字符存入字符串, 错误返回负值
    if(sprintf(str, "%d/%d/%d", 1, 2, 3) < 0) {
        fprintf(stderr, "use sprintf error.\n");
        exit(EXIT_FAILURE);
    }

    fprintf(stdout, "%s\n", str);

    return 0;
}
