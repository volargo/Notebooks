/*
 * =====================================================================================
 *
 *       Filename:  leetcode1.c
 *
 *    Description:  https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/description/
 *
 *        Version:  1.0
 *        Created:  07/27/2018 11:06:58 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

int removeDuplicates(int* nums, int numsSize)
{
    if (numsSize == 0) {
        return 0;
    }

    int     i = 0, icnt = 0;

    for (i = 0; i < numsSize; i++) {
        if (nums[i] != nums[icnt]) {
            icnt++;
            nums[icnt] = nums[i];
        }
    }
    numsSize = icnt + 1;

    return numsSize;
}
