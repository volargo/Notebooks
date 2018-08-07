/*
 * =====================================================================================
 *
 *       Filename:  strpbrk.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/01/2017 10:31:21 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (imau), wood@khan.ren
 *   Organization:  zy.imau.edu.cn
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    char *p, str[] = "hola, sunflower girl.";

    // char *strpbrk(const char *s, const char *accept);
    p = strpbrk(str, "hl");    // 返回指向第一个和第二个参数中任意一个字符匹配的最左边的一个字符.
    fprintf(stdout, "%s\n", p);
    p = strpbrk(str, "sl");    // 返回指向第一个和第二个参数中任意一个字符匹配的最左边的一个字符.
    fprintf(stdout, "%s\n", p);

    return EXIT_SUCCESS;
}
