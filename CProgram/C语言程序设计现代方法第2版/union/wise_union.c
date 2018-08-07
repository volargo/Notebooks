/*
 * =====================================================================================
 *
 *       Filename:  wise_union.c
 *
 *    Description:  使用联合构造混合的数据结构
 *
 *        Version:  1.0
 *        Created:  07/16/2017 08:56:58 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (LF), wood@khan.ren
 *   Organization:  imau
 *
 * =====================================================================================
 */
#include <stdio.h>

#define LENGTH 5

/* 构造一个混合类型的联合 */
typedef union {
    int i;
    double d;
    char *c;
} Number;

int main(void)
{
    Number num_array[5];    // 使用联合新建一个数组成员

    num_array[0].i = 5;     // 联合数组存入整型数据
    num_array[1].d = 3.14;  // 联合数组存入浮点型数据
    num_array[2].c = "A";   // 联合数组存入字符型数据

    /* 查看数据存储结果 */
    printf("%d\n", num_array[0].i);
    printf("%.2f\n", num_array[1].d);
    printf("%s\n", num_array[2].c);

    return 0;
}
