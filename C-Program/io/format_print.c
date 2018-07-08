/*
 * =====================================================================================
 *
 *       Filename:  test.c
 *
 *    Description:  printf()转换说明示例
 *
 *        Version:  1.0
 *        Created:  07/23/2017 03:13:39 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (LF), wood@khan.ren
 *   Organization:  imau
 *
 * =====================================================================================
 */
#include <stdio.h>

int main(void)
{
    int len, x;

    printf("|%8d|%8d|\n", 123, -123);
    printf("|%-8d|%8d|\n", 123, -123);
    printf("|%+8d|%+8d|\n", 123, -123);
    printf("|% 8d|% 8d|\n", 123, -123);
    printf("|%08d|%08d|\n", 123, -123);
    printf("|%-+8d|%-+8d|\n", 123, -123);
    printf("|%- 8d|% -8d|\n", 123, -123);
    printf("|%+08d|%+08d|\n", 123, -123);
    printf("|% 08d|% 08d|\n", 123, -123);

    x = 123;
    printf("%d%n\n", x, &len);
    printf("%d\n", len);

    return 0;
}
