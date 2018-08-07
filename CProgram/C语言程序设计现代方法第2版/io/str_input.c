/*
 * =====================================================================================
 *
 *       Filename:  str_input.c
 *
 *    Description:  行的输入
 *
 *        Version:  1.0
 *        Created:  07/27/2017 08:45:08 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (), wood@khan.ren
 *   Organization:  imau
 *
 * =====================================================================================
 */
#include "FatalError.h"

int main(void)
{
    char str[100];

    fgets(str, sizeof(str), stdin);
    fputs(str, stdout);

    return 0;
}
