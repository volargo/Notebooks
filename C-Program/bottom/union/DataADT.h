/*
 * =====================================================================================
 *
 *       Filename:  basic.c
 *
 *    Description:  定义依赖机器的类型(ADT接口)
 *
 *        Version:  1.0
 *        Created:  07/21/2017 11:56:18 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (LF), wood@khan.ren
 *   Organization:  imau
 *
 * =====================================================================================
 */
#ifndef BASIC_H
#define BASIC_H

typedef unsigned char BYTE;             // 可移植自定义字符存储类型
typedef unsigned short WORD;            // 可移植自定义字存储类型(x86)

typedef struct file_date BitDate;      // 结构位域(针对16位存储)
typedef union int_date UnionDate;      // 联合位域(针对16位存储)

void Print_Date(unsigned short n);      // 打印文件日期
void Demo_Reg(void);                    // 测试代码

#endif
