/*
 * =====================================================================================
 *
 *       Filename:  StackADT.h
 *
 *    Description:  栈抽象数据类型客户接口
 *
 *        Version:  5.0
 *        Created:  07/15/2017 10:27:11 PM
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

#define PUBLIC          // 成员公有
#define PRIVATE static  // 成员私有

#include <stdbool.h>    /* C99 only */

typedef int Item;

typedef struct Stack_Type *Stack;

Stack Create_Stack(void);
void Destory_Stack(Stack s);
void MakeEmpty_Stack(Stack s);
bool IsEmpty_Stack(const Stack s);
bool IsFull_Stack(const Stack s);
void Push_Stack(Stack s, Item i);
Item Pop_Stack(Stack s, Item *i);

#endif
