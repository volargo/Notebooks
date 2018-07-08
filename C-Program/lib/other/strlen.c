/*
 * =====================================================================================
 *
 *       Filename:  strlen.c
 *
 *    Description:  返回字符串的长度
 *
 *        Version:  1.0
 *        Created:  08/02/2017 10:20:49 PM
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
    char *hola = "hola, sunflower girl.";

    fprintf(stdout, "%ld\n", strlen(hola));

    return EXIT_SUCCESS;
}
