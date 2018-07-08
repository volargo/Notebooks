/*
 * =====================================================================================
 *
 *       Filename:  print_error.c
 *
 *    Description:  打印错误消息调用的次数
 *
 *        Version:  1.0
 *        Created:  07/14/2017 11:49:29 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (LF), wood@khan.ren
 *   Organization:  imau
 *
 * =====================================================================================
 */
#include <stdio.h>

void print_error(const char *message) {
    static int n = 1;   // 静态存储期限, 块作用域, 无链接

    printf("Error %d: %s\n", n++, message);
}

int main(void)
{
    register int i = 0;     // 直接寄存器存储值, 无地址不可用取地址符号访问

    for(i = 0; i < 5; i++) {
        print_error("error msg");
    }

    return 0;
}
