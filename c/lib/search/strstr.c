/*
 * =====================================================================================
 *
 *       Filename:  strstr.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/01/2017 10:49:17 AM
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

    p = strstr(str, "sun");
    fprintf(stdout, "%s\n", p);

    return EXIT_SUCCESS;
}
