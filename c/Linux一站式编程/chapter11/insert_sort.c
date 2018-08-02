/*
 *       Filename:  insert_sort.c
 *
 *    Description:  插入排序 
 *
 *        Version:  1.0
 *        Created:  07/30/2018 08:23:04 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Volargo (VL), git@volargo.com
 *   Organization:  
 *
 */

#include <stdio.h>

/**
 *      insert_sort     -       sort of integer array
 *      @array: param array
 *      @size:  array length
 *
 *      Insertion sort of integer array.
 */
void insert_sort(int *array, int size)
{
        int      i, j, key;
        for (j = 0; j < size; j++) {
                key = array[j];
                i = j - 1;
                while (i >= 0 && array[i] > key) {
                        array[i+1] = array[i];
                        i--;
                }
                array[i+1] = key;
        }
}

int main(void)
{
        int     i;
        int     test_nums[10] = {1, 999, 8512, 21, 2312, 532, 12, 89, 24, 43};

        insert_sort(test_nums, 10);

        for (i = 0; i < 10; i++) {
                printf("%d ", test_nums[i]);
        }
        printf("\n");

        return 0;
}
