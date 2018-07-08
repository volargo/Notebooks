/*
 * =====================================================================================
 *
 *       Filename:  copyfunction.c
 *
 *    Description:  string.h库中复制函数
 *
 *        Version:  1.0
 *        Created:  07/31/2017 03:28:17 PM
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

#define ECHO(str) (fprintf(stdout, "%s\n", str))

int main(void)
{
    char source[] = {'h', 'o', 'l', 'a', 'g', 'i', 'r', 'l'};
    char dest[strlen(source)];

    memcpy(dest, source, 3);
    ECHO(dest);
    memcpy(dest, source, 4);
    ECHO(dest);
    memcpy(dest, source, strlen(source));
    ECHO(dest);

    memmove(dest, source, 3);
    ECHO(dest);
    memmove(dest, source, 4);
    ECHO(dest);
    memmove(dest, source, strlen(source));
    ECHO(dest);

    strcpy(dest, source);
    ECHO(dest);

    strncpy(dest, source, 3);
    ECHO(dest);
    strncpy(dest, source, 4);
    ECHO(dest);
    strncpy(dest, source, strlen(source));
    ECHO(dest);

    return 0;
}
