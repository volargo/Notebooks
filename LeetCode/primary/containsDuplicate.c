/*
 * =====================================================================================
 *
 *       Filename:  leetcode24.c
 *
 *    Description:  https://leetcode-cn.com/explore/interview/card/top-interview-questions-easy/1/array/24/
 *
 *        Version:  1.0
 *        Created:  07/27/2018 06:40:05 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *   Organization:
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdbool.h>

int cmp(const void *a, const void *b)
{
     return (*(int *)a - *(int *)b);
}

bool containsDuplicate(int* nums, int numsSize)
{
    int     i = 0;

    qsort(nums, numsSize, sizeof(nums[0]), &cmp);
    // contains duplicate
    for (i = 0; i < numsSize - 1; i++) {
        if (nums[i] == nums[i+1]) {
            return true;
        } 
    }
    return false;
}
