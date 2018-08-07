/*
 * =====================================================================================
 *
 *       Filename:  array_struct.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/29/2018 03:35:56 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Volargo (VL), git@volargo.com
 *   Organization:  
 *
 * =====================================================================================
 */

// 定义一个由4个结构体元素组成的数组
struct complex_struct {
    double x, y;
} a[4];

// 定义一个包含数组成员的结构体
struct {
    double  x, y;
    int     count[4];
} s;
