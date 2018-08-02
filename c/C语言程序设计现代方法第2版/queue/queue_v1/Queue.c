/*
 * =====================================================================================
 *
 *       Filename:  Queue.c
 *
 *    Description:  队列抽象数据类型的实现
 *
 *        Version:  1.0
 *        Created:  07/17/2017 12:18:07 AM
 *       Revision:  Mon Jul 17 01:21:16 HKT 2017
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (LF), wood@khan.ren
 *   Organization:  imau
 *
 * =====================================================================================
 */
#include "QueueADT.h"
#include "ErrorDeal.h"

/* 队列结构 */
struct Queue_Type {
    int q_iCapactial;       // 队列长度上限
    int q_iLen;             // 当前队列长度
    int q_iHead;            // 队列首部
    int q_iTail;            // 队列尾部
    Item *data;             // 队列元素
};

/*=========================================================
 *  功能描述: 创建队列
 *  函数参数: 
 *  返回类型: Queue_Type*
 *  作者注释: 参看QueueADT.h接口描述
 *=========================================================*/
Queue Create_Queue(const int size) {
    Queue q = malloc(sizeof(struct Queue_Type));
    if (q == NULL) {
        FatalError("Error in create: queue could not be created.");
    }
    q->data = malloc(size * sizeof(Item));
    if (q->data == NULL) {
        FatalError("Error in create: queue data is null.");
    }
    q->q_iHead = 0;             // 队列首部置0
    q->q_iTail = 1;             // 队列尾部置0
    q->q_iLen = 0;              // 队列元素置0
    q->q_iCapactial = size;     // 队列最大允许长度

    return q;                   // 返回创建队列
}

/*=========================================================
 *  功能描述: 清空队列, 将队列首尾以及元素个数置0清空队列
 *  函数参数: Queue_Type*
 *  返回类型:
 *  作者注释: 队列清空就是将队列集合的限定重新初始化
 *=========================================================*/
Public void MakeEmpty_Queue(Queue q) {
    if (IsEmpty_Queue(q)) {
        FatalError("Error in make empty: queue is empty.");
    }
    q->q_iHead = 0;     // 队首数值置0
    q->q_iTail = 1;     // 队尾数值置0
    q->q_iLen = 0;      // 队列长度值置0
}

/*=========================================================
 *  功能描述: 销毁队列, 将队列内存空间释放
 *  函数参数: Queue* 类型的队列(q)
 *  返回类型: 
 *  作者注释: 不完善, 会有内存泄露
 *=========================================================*/
Public void Destory_Queue(Queue q) {
    if (q != NULL) {
        free(q->data);
        free(q);
    }
}

/*=========================================================
 *  功能描述: 判断队列是否为空
 *  函数参数: Queue_Type* 指针类型的队列(q)
 *  返回类型: 布尔值(true & false), 队列为空返回true,
 *            否则返回false
 *  作者注释: 查看传入队列元素个数是否为0即可判断队列空否
 *=========================================================*/
Public bool IsEmpty_Queue(Queue q) {
    return q->q_iLen == 0;
}

/*=========================================================
 *  功能描述: 判断队列是否已满.
 *  函数参数: Queue_Type* 指针类型的队列(q).
 *  返回类型: 布尔值(true & false).
 *  作者注释: 查看传入队列长度是否超过允许最大值判断队列满否.
 *=========================================================*/
Public bool IsFull_Queue(Queue q) {
    return q->q_iLen == q->q_iCapactial;
}

/*=========================================================
 *  功能描述: 入队操作
 *  函数参数: Queue_Type* 指针类型队列, 入队元素
 *  返回类型: 布尔值(true & false), 入队成功返回true,
 *            否则输出错误提示信息并终止程序.
 *  作者注释: 
 *=========================================================*/
Public void Enqueue_Queue(Queue q, Item x) {
    if (IsFull_Queue(q)) {
        FatalError("Error in in_queue: queue is full.");
    }
    q->q_iLen++;                    // 队列长度增加
    q->data[q->q_iTail++] = x;      // 存储入队元素数据值
}

/*=========================================================
 *  功能描述: 出队操作, 将队首位置后移, 保存出队元素
 *  函数参数: Queue_Type* 指针类型队列(q),
 *            保存出队元素的变量(x).
 *  返回类型: 布尔值(true & false), 出队成功返回true,
 *            否则返回false值.
 *  作者注释: 代码可以简写, 为阅读方便未简写,
 *            不完善, 后期新功能添加时需要重构方法
 *=========================================================*/
Public bool Dequeue_Queue(Queue q, Item *x) {
    if (IsEmpty_Queue(q)) {
        FatalError("Error in out: queue is empty.");
    }
    q->q_iLen--;                // 队列长度递减
    q->q_iHead++;               // 队首位置后移
    *x = q->data[q->q_iHead];   // 出队元素存储到另一个变量
    return true;
}

/*=========================================================
 *  功能描述: 访问队列第一项, 不改变原有队列结构
 *  函数参数: Queue_Type* 指针类型队列(q)
 *  返回类型: Item 类型的队列首项数据值(自定义数据类型Item)
 *  作者注释: 队列数据元素的类型可以通过重新封装抽象数据类型
 *            进行修改.
 *=========================================================*/
Public Item Front_Queue(Queue q) {
    if (IsEmpty_Queue(q)) {
        FatalError("Error in front: queue is empty.");
    }
    return q->data[q->q_iHead + 1];
}

/*=========================================================
 *  功能描述: 访问队列的末项, 不改变原有队列结构
 *  函数参数: Queue_Type* 指针类型队列(q)
 *  返回类型: Item 类型的队列末项数据值(自定义数据类型Item)
 *  作者注释: 
 *=========================================================*/
Public Item Rear_Queue(Queue q) {
    if (IsEmpty_Queue(q)) {
        FatalError("Error in rear: queue is empty.");
    }
    return q->data[q->q_iTail - 1];
}
