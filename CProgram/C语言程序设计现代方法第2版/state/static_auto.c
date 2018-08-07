/*
 * =====================================================================================
 *
 *       Filename:  static_auto.c
 *
 *    Description:  static存储类型
 *
 *        Version:  1.0
 *        Created:  06/03/2017 04:49:47 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (LF), wood@khan.ren
 *   Organization:  imau
 *
 * =====================================================================================
 */
#include <stdio.h>

#if 0
char digit_to_hex_char(int digit) {
    // auto 型变量每次调用函数都初始化, 某些情况下速度较慢.
    auto const char hex_chars[16] = "0123456789ABCDEF";

    return hex_chars[digit];
}
#endif

#if 1
char digit_to_hex_char(int digit) {
    // static 型变量只进行一次初始化, 函数执行速度更快.
    static const char hex_chars[16] = "0123456789ABCDEF";

    return hex_chars[digit];
}
#endif
