/*
 * =====================================================================================
 *
 *       Filename:  Queue.c
 *
 *    Description:  队列抽象数据类型的实现
 *
 *        Version:  1.0
 *        Created:  07/18/2017 08:25:05 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (LF), wood@khan.ren
 *   Organization:  imau
 *
 * =====================================================================================
 */
#include "err.h"
#include "queue.h"

/* 队列节点数据结构 */
typedef struct Queue_Node {
    Item data;                  // 队列节点数据值
    struct Queue_Node *next;    // 队列节点指针
} Node, *QueueNode;

/* 队列完整类型结构 */
typedef struct Queue_Type {
    QueueNode Front;            // 队列首节点
    QueueNode Rear;             // 队列尾节点
    int max_size;               // 队列长度
    int count_val;              // 队列项计数值
} QNode, *QueueType;

/*=========================================================
 *  功能描述: 创建队列
 *  函数参数: 队列长度(size)
 *  返回类型: 队列完整结构体(QueueType, 结构体指针)
 *  作者注释: 
 *=========================================================*/
QueueType Create_Queue(const int size) {
    QueueType q = malloc(sizeof(QueueType));
    if (q == NULL) {
        FatalError("Error in create: queue could not be created.");
    }
    // 队列首尾节点项分配内存
    q->Front = q->Rear = malloc(sizeof(QueueNode));
    if (q->Front == NULL || q->Rear == NULL) {
        FatalError("Error in create: queue front or rear has malloc failed.");
    }
    q->max_size = size;             // 参数传递队列最大长度
    q->count_val = 0;               // 初始化队列计数项为0
    q->Rear = q->Front = NULL;      // 队列首尾节点置空

    return q;
}

/*=========================================================
 *  功能描述: 快速清空队列, 通过初始化队列计数值清空
 *  函数参数: 队列完整结构体(QueueType, 结构体指针)
 *  返回类型: 布尔值, 操作成功返回true
 *  作者注释: 
 *=========================================================*/
PUBLIC int MakeEmpty_Queue(QueueType q) {
    if (IsEmpty_Queue(q)) {
        return 1;
    }
    q->count_val = 0;
    return 1;
}

/*=========================================================
 *  功能描述: 彻底清空队列, 删除队列数据彻底清空队列
 *  函数参数: 队列完整结构体(QueueType, 结构体指针)
 *  返回类型: 布尔值, 操作成功返回true
 *  作者注释: 
 *=========================================================*/
PUBLIC int ClearData_Queue(QueueType q) {
    QueueNode temp;
    // 队列不为空进行数据清空
    while (q != NULL) {
        temp = q->Front;
        q->Front = q->Front->next;
        temp = NULL;
    }
    // 检测是否成功清空队列所有数据
    if (q->Front == NULL && q->Rear == NULL) {
        return 1;
    } else {
        q->Front = q->Rear = NULL;
        return 1;
    }
}

// 销毁队列, 通过接口函数交接系统API进行内存清理
PUBLIC void Destory_Queue(QueueType q) {
    free(q);
}

// 判空队列, 计数项是否为队列项计数初始值
PUBLIC int IsEmpty_Queue(const QueueType q) {
    return q->count_val == 0;
}

// 判满队列, 通过检测标志值判断, 防止队列长度越界
PUBLIC int IsFull_Queue(const QueueType q) {
    return q->count_val == q->max_size;
}

// 队列计数, 通过查看队列计数项, 防止队列长度越界
PUBLIC int Counter_Queue(const QueueType q) {
    return q->count_val;
}

/*=========================================================
 *  功能描述: 入队操作, 队尾插入数据(非环形队列操作)
 *  函数参数: 1. 队列完整结构体(QueueType, 指针类型); 
 *            2. 入队数据值(Item, 自定义数据类型)
 *  返回类型: 布尔值, 操作成功返回true, 否则相应错误处理
 *  作者注释: 
 *=========================================================*/
PUBLIC int Enqueue_Queue(QueueType q, Item x) {
    QueueNode new_node = malloc(sizeof(QueueNode));
    if (new_node == NULL) {
        FatalError("Error in enqueue: malloc new node has failed.");
    }
    if (IsFull_Queue(q)) {
        FatalError("Error in enqueu: queue is full.");
    }
    // 如果源队列为空则将新入队数据作为队首添加
    if (IsEmpty_Queue(q)) {
        q->Front = new_node;
    }
    new_node->data = x;         // 入队数据存储
    new_node->next = NULL;      // 节点无后继指针指向
    q->Rear = new_node;         // 新入队数据节点作为队尾
    q->count_val++;             // 队列数据计数项增加

    return 1;
}

/*=========================================================
 *  功能描述: 出队操作, 队首后移进行队列数据出队
 *  函数参数: 1. 队列完整结构体(QueueType, 指针类型)
 *            2. 出队数据存储变量(Item, 自定义数据类型)
 *  返回类型: 布尔值, 操作成功返回true, 否则相应错误处理
 *  作者注释: 
 *=========================================================*/
PUBLIC int Dequeue_Queue(QueueType q, Item  *x) {
    QueueNode old_node = malloc(sizeof(QueueNode));
    if (old_node == NULL) {
        FatalError("Error in dequeue: malloc old node has failed.");
    }
    if (IsEmpty_Queue(q)) {
        FatalError("Error in dequeue: queue is empty.");
    }
    *x = q->Front->data;            // 出队数据项存储
    old_node = q->Front;            // 队首节点拷贝
    q->Front = q->Front->next;      // 队首节点重新定位
    free(old_node);                 // 清理无用节点内存
    
    // 出队数据是否末项处理
    if (q->count_val == 0) {
        q->Rear = NULL;
    }
    return 1;
}

// 查看队首数据
PUBLIC Item Front_Queue(const QueueType q) {
    if (IsEmpty_Queue(q)) {
        FatalError("Error in cat front: queue is empty.");
    }
    return q->Front->data;
}

// 查看队尾数据
PUBLIC Item Rear_Queue(const QueueType q) {
    if (IsEmpty_Queue(q)) {
        FatalError("Error in cat rear: queue is empty.");
    }
    return q->Rear->data;
}
