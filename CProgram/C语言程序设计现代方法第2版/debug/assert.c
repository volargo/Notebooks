/*
 * =====================================================================================
 *
 *       Filename:  assert.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/04/2017 12:10:31 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (imau), wood@khan.ren
 *   Organization:  zy.imau.edu.cn
 *
 * =====================================================================================
 */
#define NDEBUG  // 禁止assert宏进行错误检测
#include <assert.h>

int main(void)
{
    int i = -1;
    int a[10];

    // 参数不为0, assert无行为; 否则向stderr标准错误流写一条消息, 并且调用abort函数进行程序终止
    assert(0 <= i && i <= 9);
    a[i] = 10;

    return 0;
}
