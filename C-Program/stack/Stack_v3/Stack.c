/*
 * =====================================================================================
 *
 *       Filename:  StackADTv3.h
 *
 *    Description:  使用定长数组实现栈抽象数据类型
 *
 *        Version:  3.0
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

#define STACK_SIZE 100

struct stack_type {
    Item contents[STACK_SIZE];
    int top;
};

static void Terminate(const char *message) {
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

Stack Create_Stack(void) {
    Stack s = malloc(sizeof(struct stack_type));
    if (s == NULL) {
        Terminate("Error in create: stack can't be created.");
    }
    s->top = 0;
    return s;
}

void Destory_Stack(Stack s) {
    free(s);
}

void MakeEmpty_Stack(Stack s) {
    s->top = 0;
}

bool IsEmpty_Stack(const Stack s) {
    return s->top == 0;
}

bool IsFull_Stack(const Stack s) {
    return s->top == STACK_SIZE;
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
