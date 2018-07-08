/*
 * =====================================================================================
 *
 *       Filename:  offsetof.c
 *
 *    Description:  offsetof的使用
 *
 *        Version:  1.0
 *        Created:  07/22/2017 06:10:30 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (LF), wood@khan.ren
 *   Organization:  imau
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stddef.h>

struct s {
    char a;
    int b[2];
    float c;
} slen;

int main(void)
{
    printf("a length in struct s: %ld, offset is: %ld\n", sizeof(slen.a), offsetof(struct s, a));
    printf("b length in struct s: %ld, offset is: %ld\n", sizeof(slen.b), offsetof(struct s, b));
    printf("c length in struct s: %ld, offset is: %ld\n", sizeof(slen.c), offsetof(struct s, c));

    printf("all structure size is: %ld\n", sizeof(struct s));

    return 0;
}
