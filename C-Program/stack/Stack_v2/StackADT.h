/*
 * =====================================================================================
 *
 *       Filename:  StackADT.h
 *
 *    Description:  栈模块实现抽象数据类型的封装(利用不完整类型进行接口封装)
 *
 *        Version:  1.0
 *        Created:  07/15/2017 04:37:07 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (LF), wood@khan.ren
 *   Organization:  imau
 *
 * =====================================================================================
 */
#ifndef _STACKADT_H
#define _STACKADT_H

#include <stdbool.h>    /* C99 only */

typedef struct Stack_Type *Stack;   // 不完整类型进行抽象数据类型封装

Stack Create(void);
void Destory_Stack(Stack s);
void Make_Empty(Stack s);
bool Is_Empty(const Stack s);
bool Is_Full(const Stack s);
void Push_Stack(Stack s, int i);
int Pop_Stack(Stack s);

#endif
