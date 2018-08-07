/*
 * =====================================================================================
 *
 *       Filename:  merge_sort.c
 *
 *    Description:  归并排序 
 *
 *        Version:  1.0
 *        Created:  07/31/2018 05:05:17 PM
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
#include <time.h>

#define LEN 20

/**
 *      merge        -       merge sorted array
 *      @nums:  integer array
 *      @start: the starting of an integer array
 *      @mid:   the mid of an integer array
 *      @end:   the end of an integer array
 *
 *      merge two array
 */
void merge(int* nums, int start, int mid, int end)
{
        int     n1 = mid - start + 1;
        int     n2 = end - mid;
        int     left[n1], right[n2];
        int     i, j, k;
        
        for (i = 0; i < n1; i++) { /* left holds nums[start...mid] */
                left[i] = nums[start+i];
        }
        for (j = 0; j < n2; j++) { /* right holds nums[mid+1...end] */
                right[j] = nums[mid+1+j];
        }

        i = j = 0;
        k = start;
        while (i < n1 && j < n2) {
                if (left[i] < right[j])
                        nums[k++] = left[i++];
                else
                        nums[k++] = right[j++];
        }

        while (i < n1) { /* left is not exhausted */
                nums[k++] = left[i++];
        }
        while (j < n2) { /* right is not exhausted */
                nums[k++] = right[j++];
        }
}

/**
 *      sort    -       merge sort main function
 *      @nums:  integer array
 *      @start: starting of integer array
 *      @end:   end of integer array
 *
 *      using recursive merge sort
 */
void sort(int* nums, int start, int end)
{
        int     mid;

        if (start < end) {
                mid = (start + end) / 2;
                sort(nums, start, mid);
                sort(nums, mid+1, end);
                merge(nums, start, mid, end);
        }
}

int main(void)
{
        int     test_nums[LEN] = {0};
        int     i;

        srand(time(NULL));
        for (i = 0; i < LEN; i++) {
                test_nums[i] = rand() % 1000;
        }

        sort(test_nums, 0, LEN - 1);
        for (i = 0; i < LEN; i++) {
                printf("%d ", test_nums[i]);
        }
        printf("\n");

        return 0;
}
