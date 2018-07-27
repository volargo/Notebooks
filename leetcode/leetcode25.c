/*
 * =====================================================================================
 *
 *       Filename:  leetcode25.c
 *
 *    Description:  https://leetcode-cn.com/explore/interview/card/top-interview-questions-easy/1/array/25/ 
 *
 *        Version:  1.0
 *        Created:  07/27/2018 09:17:58 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

int singleNumber(int* nums, int numsSize)
{
    if (nums == '\0') {
        return '\0';
    } else if (numsSize == 1) {
        return nums[0];
    }

    int     i;
    int     ires = 0;

    for (i = 0; i < numsSize; i++) {
        ires = nums[i] ^ ires;
    }
    return ires;
}
