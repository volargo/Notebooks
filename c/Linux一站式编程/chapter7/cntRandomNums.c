/*
 * =====================================================================================
 *
 *       Filename:  cntRandomNums.c
 *
 *    Description:  统计随机数 
 *
 *        Version:  1.0
 *        Created:  07/29/2018 03:53:10 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Volargo (VL), git@volargo.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define N 100000

int a[N];

void gen_random(int upper_bound)
{
    int     i;
    for (i = 0; i < N; i++) {
        a[i] = rand() % upper_bound;
    }
}

int howmany(int value)
{
    int icnt = 0, i;

    for (i = 0; i < N; i++) {
        if (a[i] == value) {
            ++icnt;
        }
    }

    return icnt;
}

int main(void)
{
    int i;

    gen_random(10);
    
    printf("value\thow many\n");
    for (i = 0; i < 10; i++) {
        printf("%d\t%d\n", i, howmany(i));
    }

    return 0;
}
