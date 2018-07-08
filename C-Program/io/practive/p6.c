/*
 * =====================================================================================
 *
 *       Filename:  prac6.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/29/2017 11:43:19 AM
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
    int widget;
    
    scanf("%d", &widget);

    printf(widget == 1 ? "%d widget\n" : "%d widgets\n", widget);

    return 0;
}
