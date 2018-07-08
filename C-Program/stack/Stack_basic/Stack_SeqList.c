/*
 * =====================================================================================
 *
 *       Filename:  stack_seqList.c
 *
 *    Description:  使用链表实现栈模块功能
 *
 *        Version:  1.0
 *        Created:  07/15/2017 03:51:50 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (LF), wood@khan.ren
 *   Organization:  imau
 *
 * =====================================================================================
 */
#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>

// 栈结构
typedef struct Node {
    int data;
    struct Node *next;
} Stack_SeqList;

// 链表起始点置空
static struct Node *top = NULL;

// 错误输出
static void Terminate(char *message) {
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

// 清空栈
void Make_Empty(void) {
    while (!Is_Empty()) {
        Pop_Stack();
    }
}

// 判栈空
bool Is_Empty(void) {
    return top == NULL;
}

// 判栈满
bool Is_Full(void) {
    return false;
}

// 压栈操作
void Push_Stack(int i) {
    Stack_SeqList *new_node = malloc(sizeof(Stack_SeqList));    // 链表游标
    
    // 检测内存是否正确分配
    if (new_node == NULL) {
        Terminate("Error in push: stack is full.");
    }

    new_node->data = i;     // 数据入栈
    new_node->next = top;   // 栈顶指针后移
    top = new_node;         // 定位栈顶位置
}

int Pop_Stack(void) {
    Stack_SeqList *old_top;
    int i;

    if (Is_Empty()) {
        Terminate("Error in pop: stack is empty.");
    }

    old_top = top;
    i = top->data;
    top = top->next;
    free(old_top);
    return i;
}
