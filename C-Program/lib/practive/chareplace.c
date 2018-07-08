/*
 * =====================================================================================
 *
 *       Filename:  chareplace.c
 *
 *    Description:  字符替换
 *
 *        Version:  1.0
 *        Created:  08/03/2017 11:02:27 PM
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

char *char_replace(char *s, int n) {
    char *p;

    // 将一个以空字符结尾的字符串的最后n个字符替换指定字符
    p = &s[strlen(s) - n];
    memset(p, '!', n);

    return s;
}
