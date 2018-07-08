/*
 * =====================================================================================
 *
 *       Filename:  scanf.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/23/2017 06:54:30 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (LF), wood@khan.ren
 *   Organization:  imau
 *
 * =====================================================================================
 */
#include <stdio.h>

int main(void)
{
    unsigned char str[L_tmpnam];

    fscanf(stdin, "%[ABC]", str);
    fprintf(stdout, "%s\n", str);

    return 0;
}
