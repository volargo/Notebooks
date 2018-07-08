/*
 * =====================================================================================
 *
 *       Filename:  Queue_TypeADT.h
 *
 *    Description:  队列抽象数据类型的接口(使用链表构造)
 *
 *        Version:  1.0
 *        Created:  07/17/2017 05:21:58 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (LF), wood@khan.ren
 *   Organization:  imau
 *
 * =====================================================================================
 */
#ifndef __QUEUEADT_H__      // 结构文件检测，防止编译时成员重定义行为
#define __QUEUEADT_H__

#define PUBLIC
#define PRIVATE static

typedef int Item;   // 队列数据类型指定
typedef struct Queue_Node *QueueNode;   // 不完整类型定义(数据封装), 队列节点结构体
typedef struct Queue_Type *QueueType;   // 不完整类型定义(数据封装), 队列完整结构体

QueueType Create_Queue(const int size);                     // 创建队列
PUBLIC int MakeEmpty_Queue(QueueType q);                    // 快速清空队列
PUBLIC int ClearData_Queue(QueueType q);                    // 删除队列数据项
PUBLIC void Destory_Queue(QueueType q);                     // 销毁队列
PUBLIC int IsEmpty_Queue(const QueueType q);                // 判空队列
PUBLIC int IsFull_Queue(const QueueType q);                 // 判满队列
PUBLIC int Counter_Queue(const QueueType q);                // 队列项计数
PUBLIC int Enqueue_Queue(QueueType q, Item x);              // 出队列
PUBLIC int Dequeue_Queue(QueueType q, Item *x);             // 入队列
PUBLIC Item Front_Queue(const QueueType q);                 // 查看队列第一项(不改变队列)
PUBLIC Item Rear_Queue(const QueueType q);                  // 查看队列的末项(不改变队列)

#endif
