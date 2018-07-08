/*
 * =====================================================================================
 *
 *       Filename:  strcat.c
 *
 *    Description:  strcat()函数的使用
 *
 *        Version:  1.0
 *        Created:  07/31/2017 09:27:58 PM
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

#define STRING_LEN 100

int main(void)
{
    char s1[100] = "Hola, sunflower girl. ";
    char s2[100] = "Nice to meet u.";

    // char *strcat(char *dest, const char *src);
    strcat(s1, s2);
    fprintf(stdout, "%s\n", s1);

    return 0;
}
