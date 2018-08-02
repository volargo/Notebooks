/*
 * =====================================================================================
 *
 *       Filename:  gdb_example.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/30/2018 06:57:39 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Volargo (VL), git@volargo.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>

int add_range(int low, int high)
{
        int     i, sum = 0;
        for (i = low; i <= high; i++) {
                sum = sum + i;
        }

        return sum;
}

int main(void)
{
        int     result[100] = {0};

        result[0] = add_range(1, 10);
        result[1] = add_range(1, 100);
        printf("result[0]=%d\nresult[1]=%d\n", result[0], result[1]);

        return 0;
}

