/*
 * =====================================================================================
 *
 *       Filename:  p8.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/29/2017 12:16:24 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (imau), wood@khan.ren
 *   Organization:  zy.imau.edu.cn
 *
 * =====================================================================================
 */
#include <stdio.h>

int main(void)
{
    char str[10];

    scanf("%5c", str);
    fprintf(stdout, "%s\n", str);

    scanf("%1s", str);
    fprintf(stdout, "%s\n", str);

    return 0;
}
