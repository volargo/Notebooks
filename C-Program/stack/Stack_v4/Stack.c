/*
 * =====================================================================================
 *
 *       Filename:  Stack_Array_v4.c
 *
 *    Description:  栈抽象数据类型的实现
 *
 *        Version:  4.0
 *        Created:  07/15/2017 08:43:37 PM
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

struct Stack_Type {
	Item *contents;
	int top;
	int size;
};

// 程序错误检测输出
static void Terminate(const char *message) {
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

Stack Create_Stack(int size) {
    Stack s = malloc(sizeof(struct Stack_Type));
    if (s == NULL) {
        Terminate("Error in create: stack could not be created.");
    }
    s->contents = malloc(size * sizeof(Item));      // 动态数组分配
    if (s->contents == NULL) {
        free(s);
        Terminate("Error in create: stack could not be created.");
    }
    s->top = 0;
    s->size = size;
    return s;
}

void Destory_Stack(Stack s) {
    free(s->contents);
    free(s);
}

void MakeEmpty_Stack(Stack s) {
    s->top = 0;
}

bool IsEmpty_Stack(const Stack s) {
    return s->top == 0;
}

bool IsFull_Stack(const Stack s) {
    return s->top == s->size;
}

void Push_Stack(Stack s, Item i) {
    if (IsFull_Stack(s)) {
        Terminate("Error in push: stack is full.");
    }
    s->contents[s->top++] = i;
}

Item Pop_Stack(Stack s) {
    if (IsEmpty_Stack(s)) {
        Terminate("Error in pop: stack is empty.");
    }
    return s->contents[--s->top];
}
