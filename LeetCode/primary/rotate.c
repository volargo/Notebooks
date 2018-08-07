/*
 * =====================================================================================
 *
 *       Filename:  leetcode23.c
 *
 *    Description:  https://leetcode-cn.com/explore/interview/card/top-interview-questions-easy/1/array/23/
 *
 *        Version:  1.0
 *        Created:  07/27/2018 04:39:38 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

/*
 * Method 1
 */
void rotate1(int* nums, int numsSize, int k)
{
    if ( (nums == '\0') || (k == 0) || (k % numsSize == 0) ) {
        return;
    }
    int     arr[numsSize];
    int     i = 0;

    for (i = 0; i < numsSize; i++) {
        arr[i] = nums[i];
    }

    for (i = 0; i < numsSize; i++) {
        nums[(i + k) % numsSize] = arr[i];
    }
}


/*
 * Method 2
 */
void reverse(int* arr, int start, int end)
{
    int     tmp = 0;

    while (start < end) {
        tmp = arr[start];
        arr[start++] = arr[end];
        arr[end--] = tmp;
    }
}

void rotate2(int* nums, int numsSize, int k)
{
    if (nums == '\0' || k == 0 || k % numsSize == 0) {
        return;
    }
    reverse(nums, 0, numsSize - 1 - k);
    reverse(nums, numsSize - k, numsSize - 1);
    reverse(nums, 0, numsSize - 1);
}
