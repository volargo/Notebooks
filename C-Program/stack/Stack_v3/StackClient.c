/*
 * =====================================================================================
 *
 *       Filename:  StackClient.c
 *
 *    Description:  测试栈抽象数据类型
 *
 *        Version:  1.0
 *        Create_Stackd:  07/15/2017 05:01:28 PM
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

int main(void)
{
    Stack s1, s2;
   
    int n;

    s1 = Create_Stack();
    s2 = Create_Stack();

    Push_Stack(s1, 1);
    Push_Stack(s1, 2);

    n = Pop_Stack(s1);
    printf("Popped %d from s1.\n", n);
    Push_Stack(s2, n);
    n = Pop_Stack(s1);
    printf("Popped %d from s1.\n", n);
    Push_Stack(s2, n);

    Destory_Stack(s1);

    while (!IsEmpty_Stack(s2)) {
        printf("Popped %d from s2.\n", Pop_Stack(s2));
    }

    Push_Stack(s2, 3);
    MakeEmpty_Stack(s2);
    if (IsEmpty_Stack(s2)) {
        printf("s2 is empty.\n");
    } else {
        printf("s2 is not empty.\n");
    }

    Destory_Stack(s2);

    return 0;
}
