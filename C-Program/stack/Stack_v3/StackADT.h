/*
 * =====================================================================================
 *
 *       Filename:  StackADT.h
 *
 *    Description:  改变栈抽象数据类型中数据类型的类型
 *
 *        Version:  3.0
 *        Created:  07/15/2017 07:17:31 PM
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

typedef int Item;

typedef struct stack_type *Stack;

Stack Create_Stack(void);
void Destory_Stack(Stack s);
void MakeEmpty_Stack(Stack s);
bool IsEmpty_Stack(const Stack s);
bool IsFull_Stack(const Stack s);
void Push_Stack(Stack s, Item i);
Item Pop_Stack(Stack s);

#endif
