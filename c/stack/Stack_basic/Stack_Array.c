/*
 * =====================================================================================
 *
 *       Filename:  stack.c
 *
 *    Description:  栈模块的实现
 *
 *        Version:  1.0
 *        Created:  07/15/2017 03:29:32 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (LF), wood@khan.ren
 *   Organization:  imau
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

#define STACK_SIZE 100

#if 1
static int contents[STACK_SIZE];
static int top = 0;

// 只能在模块内使用, 不属于程序接口
static void Terminate(const char *message) {
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

// 栈置空
void Make_Empty(void) {
    top = 0;
}

// 判栈空
bool Is_Empty(void) {
    return top == 0;
}

// 判栈满
bool Is_Full(void) {
    return top == STACK_SIZE;
}

// 压栈操作
void Push_Stack(int i) {
    if (Is_Full()) {
        Terminate("Error in push: stack is full.");
    }
    contents[top++] = i;
}

// 弹栈操作
int Pop_Stack(void) {
    if (Is_Empty()) {
        Terminate("Error in pop: stack is empty.");
    }
    return contents[--top];
}
#endif

#if 0 // 另外一种书写风格
#define PUBLIC /* empty */
#define PRIVATE static

PRIVATE int contents[STACK_SIZE];
PRIVATE int top = 0;

PRIVATE void Terminate(const char *message) {
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

PUBLIC void Make_Empty(void) {
    top = 0;
}

PUBLIC bool Is_Empty(void) {
    return top == 0;
}

PUBLIC bool Is_Full(void) {
    return top == STACK_SIZE;
}

PUBLIC void Push_Stack(int i) {
    if (Is_Full()) {
        Terminate("Error in push: stack is full.");
    }
    contents[top++] = i;
}

PUBLIC int Pop_Stack(void) {
    if (Is_Empty()) {
        Terminate("Error in pop: stack is empty.");
    }
    return contents[--top];
}
#endif
