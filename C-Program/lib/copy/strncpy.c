/*
 * =====================================================================================
 *
 *       Filename:  strncpy.c
 *
 *    Description:  strncpy()函数的使用
 *
 *        Version:  1.0
 *        Created:  07/31/2017 09:25:04 PM
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
    char *source = "hola, sunflower girl.";
    char dest[strlen(source)];

    strncpy(dest, source, strlen(source));
    fprintf(stdout, "%s\n", dest);

    return EXIT_SUCCESS;
}
