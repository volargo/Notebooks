/*
 * =====================================================================================
 *
 *       Filename:  test.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/30/2017 01:08:15 PM
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
    char str[10], t[10];

    fgets(t, sizeof(t), stdin);
    sscanf(t, "%[^ABC]", str);
    printf("%s\n", str);

    return 0;
}
