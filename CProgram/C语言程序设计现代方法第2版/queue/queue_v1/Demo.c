/*
 * =====================================================================================
 *
 *       Filename:  QueueClient.c
 *
 *    Description:  队列测试代码
 *
 *        Version:  1.0
 *        Created:  07/17/2017 11:51:08 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (LF), wood@khan.ren
 *   Organization:  imau
 *
 * =====================================================================================
 */
#include "ErrorDeal.h"
#include "QueueADT.h"
#include <stdio.h>

int main(void)
{
    int size;
    Item x;

    printf("Please enter queue length: ");
    scanf("%d", &size);
    Queue q = Create_Queue(size);
    printf("Please enter queue elements: ");
    while (!IsFull_Queue(q)) {
        scanf("%d", &x);
        Enqueue_Queue(q, x);
    }

    printf("Front elements: %d\n", Front_Queue(q));
    printf("Rear elements: %d\n", Rear_Queue(q));

    if (Dequeue_Queue(q, &x)) {
        printf("Dequeue elements: %d\n", x);
    }

    return 0;
}
