/*
 * =====================================================================================
 *
 *       Filename:  numchar.c
 *
 *    Description:  查找字符在字符串中国出现的次数.
 *
 *        Version:  1.0
 *        Created:  08/03/2017 10:34:13 PM
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

int numchar(const char *s, char ch) {
    int count = 0;

    s = strchr(s, ch);
    while (s != NULL) {
        count++;
        s = strchr(s+1, ch);
    }
    return count;
}

int main(void)
{
    int n;
    char *str = "hola, sunflower girl. nice to meet u. what are you doing now?";

    n = numchar(str, 't');
    fprintf(stdout, "%d\n", n);

    return EXIT_SUCCESS;
}
