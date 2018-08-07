/*
 * =====================================================================================
 *
 *       Filename:  xor.c
 *
 *    Description:  XOR加密
 *
 *        Version:  1.0
 *        Created:  07/21/2017 06:15:55 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (LF), wood@khan.ren
 *   Organization:  imau
 *
 * =====================================================================================
 */
#include <ctype.h>
#include <stdio.h>

#define KEY '&'     // 密钥

int main(void)
{
    int orig_char = 0x0000, new_char = 0x0000;

    while ((orig_char = getchar()) != EOF && orig_char != '0') {
        new_char = orig_char ^ KEY;
        if (isprint(orig_char) && isprint(new_char)) {
            putchar(new_char);
        } else {
            putchar(orig_char);
        }
    }

    return 0;
}
