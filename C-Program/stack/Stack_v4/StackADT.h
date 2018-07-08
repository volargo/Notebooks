/*
 * =====================================================================================
 *
 *       Filename:  StackADT.h
 *
 *    Description:  栈数据结构抽象数据类型接口(使用不完整类型进行封装)
 *
 *        Version:  1.0
 *        Created:  07/15/2017 08:34:57 PM
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

#include <stdbool.h>

typedef int Item;

typedef struct Stack_Type *Stack;

Stack Create_Stack(int size);
void Destory_Stack(Stack s);
void MakeEmpty_Stack(Stack s);
bool IsEmpty_Stack(const Stack s);
bool IsFull_Stack(const Stack s);
void Push_Stack(Stack s, Item i);
Item Pop_Stack(Stack s);

#endif
