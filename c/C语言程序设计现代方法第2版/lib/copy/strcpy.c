/*
 * =====================================================================================
 *
 *       Filename:  strcpy.c
 *
 *    Description:  strcpy()函数的使用
 *
 *        Version:  1.0
 *        Created:  07/31/2017 06:47:22 PM
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
#include <string.h>

int main(void)
{
    char *source = "hola, sunflower girl.";
    char dest[strlen(source)];

    // char *strcpy(char *dest, const char *src);
    strcpy(dest, source);
    fprintf(stdout, "%s\n", dest);

    return 0;
}
