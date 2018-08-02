/*
 * =====================================================================================
 *
 *       Filename:  trand.c
 *
 *    Description:  测试伪随机序列生成函数
 *
 *        Version:  1.0
 *        Created:  08/04/2017 07:26:50 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (imau), wood@khan.ren
 *   Organization:  zy.imau.edu.cn
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
    int i, seed;

    printf("This program displays the first five values of rand.\n");

    for (;;) {
        for (i = 0; i < 5; i++) {
            printf("%d ", rand());
        }
        printf("\n\n");
        printf("Enter new seed value (0 to terminate): ");
        scanf("%d", &seed);
        if (seed == 0) {
            break;
        }
        srand(seed);
    }

    return 0;
}
