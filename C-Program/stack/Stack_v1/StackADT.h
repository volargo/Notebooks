/*
 * =====================================================================================
 *
 *       Filename:  StackADT.h
 *
 *    Description:  栈抽象数据类型模块接口(可以拥有该对象的多个实例), 仅作为基础设计思路
 *
 *        Version:  1.0
 *        Created:  07/15/2017 04:22:37 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (LF), wood@khan.ren
 *   Organization:  imau
 *
 * =====================================================================================
 */
#include <stdbool.h>

#ifndef STACKADT_H
#define STACKADT_H

#define STACK_MAXSIZE 100

typedef struct {
    int contents[STACK_MAXSIZE];
    int top;
} Stack;

void Make_Empty(Stack *s);
bool Is_Empty(const Stack *s);      // 这里传递Stack指针较传递Stack值更加有效, 避免数据结构被复制
bool Is_Full(const Stack *s);       // 同理传递Stack指针较传递Stack值更加有效, 避免数据结构被复制
void Push_Stack(Stack *s, int i);
int Pop_Stack(Stack *s, int *i);

#endif
