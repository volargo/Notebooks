/*
 * =====================================================================================
 *
 *       Filename:  StackADT.h
 *
 *    Description:  使用定长数组实现栈抽象数据类型
 *
 *        Version:  1.0
 *        Created:  07/15/2017 05:25:16 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (LF), wood@khan.ren
 *   Organization:  imau
 *
 * =====================================================================================
 */
#include "StackADT.h"
#include <stdio.h>
#include <stdlib.h>

// 数组限定长度
#define STACK_SIZE 100

// 存储栈类型的结构体
struct Stack_Type {
    int contents[STACK_SIZE];   // 存储栈数据数组
    int top;    // 栈顶标志
};

static void Terminate(const char *message) {
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

// 创建栈结构
Stack Create(void) {
    Stack s = malloc(sizeof(struct Stack_Type));        // 堆空间分配栈结构
    if (s == NULL) {
        Terminate("Error in create: stack can't be created.");
    }
    s->top = 0;     // 初始化栈为空, 即栈顶位置为0(或者可以存入-1)
    return s;
}

// 销毁栈空间
void Destory_Stack(Stack s) {
    free(s);
}

// 清空栈
void Make_Empty(Stack s) {
    s->top = 0;     // 栈顶置0清空栈
}

// 判栈空
bool Is_Empty(const Stack s) {
    return s->top == 0;     // 栈顶标志是否为0判断栈空
}

// 判栈满
bool Is_Full(const Stack s) {
    return s->top == STACK_SIZE;    // 栈空间顶部是否达到允许最大值
}

// 压栈操作
void Push_Stack(Stack s, int i) {
    if (Is_Full(s)) {
        Terminate("Error in push: stack is full.");
    }
    s->contents[s->top++] = i;      // 数据入栈, 栈顶标志上移
}

// 弹栈操作
int Pop_Stack(Stack s) {
    if (Is_Empty(s)) {
        Terminate("Error in pop: stack is empty.");
    }
    return s->contents[--s->top];   // 数据弹栈, 栈顶标志下移
}
