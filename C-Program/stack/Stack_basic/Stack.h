/*
 * =====================================================================================
 *
 *       Filename:  stack.h
 *
 *    Description:  栈模块的接口
 *
 *        Version:  1.0
 *        Created:  07/14/2017 10:19:09 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (LF), wood@khan.ren
 *   Organization:  imau
 *
 * =====================================================================================
 */
#ifndef _STACK_H
#define _STACK_H

#include <stdbool.h>    /* C99 only */

void Make_Empty(void);  // 栈置空
bool Is_Empty(void);    // 判栈空
bool Is_Full(void);     // 判栈满
void Push_Stack(int i); // 压栈操作
int Pop_Stack(void);    // 弹栈操作

#endif
