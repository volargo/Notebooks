/*
 * =====================================================================================
 *
 *       Filename:  QueueADT.h
 *
 *    Description:  队列抽象类型的接口(使用变长数组实现接口)
 *
 *        Version:  1.0
 *        Created:  07/16/2017 11:58:42 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (LF), wood@khan.ren
 *   Organization:  imau
 *
 * =====================================================================================
 */
#ifndef _QUEUEADT_H
#define _QUEUEADT_H

#include <stdbool.h>    /* C99 only */

#define Public          // 成员公有
#define Private static  // 成员私有
#define Item int        // 队列元素类型

typedef struct Queue_Type *Queue;       // 利用不完整类型定义进行接口数据封装(信息隐藏)

Queue Create_Queue(const int);             // 创建队列
Public void MakeEmpty_Queue(Queue);           // 清空队列
Public void Destory_Queue(Queue);             // 销毁队列
Public bool IsEmpty_Queue(Queue);             // 判空队列
Public bool IsFull_Queue(Queue);              // 判满队列
Public void Enqueue_Queue(Queue, Item);     // 出队列
Public bool Dequeue_Queue(Queue, Item *);    // 入队列
Public Item Front_Queue(Queue);               // 查看队列第一项(不改变队列)
Public Item Rear_Queue(Queue);                // 查看队列的末项(不改变队列)

#endif
