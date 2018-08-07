/*
 * =====================================================================================
 *
 *       Filename:  Demo.c
 *
 *    Description:  队列实现测试代码
 *
 *        Version:  1.0
 *        Created:  07/18/2017 05:31:26 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (LF), wood@khan.ren
 *   Organization:  imau
 *
 * =====================================================================================
 */
#include "queue.h"
#include "err.h"

int main(void)
{
    int queue_len;
    Item x;

    printf("Please enter queue length: ");
    scanf("%d", &queue_len);
    QueueType qp = Create_Queue(queue_len);
    printf("Please enter enqueue elements: ");
    while (!IsFull_Queue(qp)) {
        scanf("%d", &x);
        Enqueue_Queue(qp, x);
    }
    printf("Front of queue elements: %d\n", Front_Queue(qp));
    printf("Rear of queue elements: %d\n", Rear_Queue(qp));

    if (Dequeue_Queue(qp, &x)) {
        printf("dequeue elements: %d\n", x);
    }

    return 0;
}
