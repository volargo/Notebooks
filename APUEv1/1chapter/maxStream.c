/*
 * =====================================================================================
 *
 *       Filename:  max_stream.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/08/2017 06:35:57 PM
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
    printf("max open stream: %d\n", FOPEN_MAX);      /* Print 16 */

    return 0;
}
