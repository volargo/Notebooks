/*
 * =====================================================================================
 *
 *       Filename:  strspn.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/01/2017 10:38:31 AM
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
    size_t n;
    char str[] = "hola, sunflower girl.";

    // size_t strspn(const char *s, const char *accept);
    // 返回第一个不属于该搜索字符组在源字符串的下标
    n = strspn(str, "hola");
    printf("%c\n", str[n]);    // print ','

    // size_t strcspn(const char *s, const char *reject);
    // 返回第一个属于搜索字符数组在源字符串中的下标
    n = strcspn(str, "hola");
    printf("%c\n", str[n]);    // print 'h'

    return EXIT_SUCCESS;
}
