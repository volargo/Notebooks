/*
 * =====================================================================================
 *
 *       Filename:  strncat.c
 *
 *    Description:  strncat()函数的使用
 *
 *        Version:  1.0
 *        Created:  07/31/2017 09:31:29 PM
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
    char s1[50] = "hola, ";
    char s2[50] = "sunflower girl.";

    // char *strncat(char *dest, const char *src, size_t n);
    strncat(s1, s2, 100);
    fprintf(stdout, "%s\n", s1);

    return EXIT_SUCCESS;
}
