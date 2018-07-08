/*
 * =====================================================================================
 *
 *       Filename:  Stack_SeqList.c
 *
 *    Description:  使用链表实现栈抽象数据类型
 *
 *        Version:  1.0
 *        Created:  07/15/2017 10:47:50 PM
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
#include "StackADT.h"

struct Node
{
    Item data;
    struct Node *next; 
};

struct Stack_Type {
    struct Node *top;
};

static void Terminate(const char *message)
{
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

Item x;

Stack Create_Stack(void)
{
    Stack s = malloc(sizeof(struct Stack_Type));
    if (s == NULL) {
        Terminate("Error in create: stack could not be created.");
    }
    s->top = NULL;      // 链表创建时需要首节点置空
    return s;       // 返回指向链表指针
}

void Destory_Stack(Stack s)
{
    MakeEmpty_Stack(s);
    free(s);
}

void MakeEmpty_Stack(Stack s)
{
    while (!IsEmpty_Stack(s))
    {
        Pop_Stack(s, &x);
    }
}

bool IsEmpty_Stack(const Stack s)
{
    return s->top == NULL;
}

bool IsFull_Stack(const Stack s)
{
    if (s == NULL)
    {
        return true;
    }
    return false;
}

void Push_Stack(Stack s, Item i)
{
    struct Node *new_node = malloc(sizeof(struct Node));    // 新建链表节点
    if (new_node == NULL)
    {
        Terminate("Error in push: stacl is full.");
    }
    new_node->data = i;
    new_node->next = s->top;
    s->top = new_node;
}

Item Pop_Stack(Stack s, Item *i)
{
    struct Node *old_top;
    if (IsEmpty_Stack(s))
    {
        Terminate("Error in pop: stack is empty.");
    }

    old_top = s->top;
    *i = old_top->data;
    s->top = old_top->next;
    free(old_top);
    return *i;
}
