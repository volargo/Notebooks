/*
 * =====================================================================================
 *
 *       Filename:  strtok.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/01/2017 10:53:00 AM
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
    char date[] = "August  1,2017";
    char *p;

    p = strtok(date, " \t");
    printf("%s\n", p);

    p = strtok(NULL, " \t,");
    printf("%s\n", p);

    p = strtok(NULL, " \t");
    printf("%s\n", p);

    return EXIT_SUCCESS;
}
