/*
 * =====================================================================================
 *
 *       Filename:  leetcode22.c
 *
 *    Description:  https://leetcode-cn.com/explore/interview/card/top-interview-questions-easy/1/array/22/
 *
 *        Version:  1.0
 *        Created:  07/27/2018 12:08:41 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

int maxProfit(int* prices, int pricesSize)
{
    int     i = 0;
    int     res = 0;

    for (i = 1; i < pricesSize; i++) {
        if (prices[i] > prices[i-1]) {
            res += prices[i] - prices[i-1];
        }
    }

    return res;
}
