/*
 * =====================================================================================
 *
 *       Filename:  FileDate.c
 *
 *    Description:  文件日期(ADT实现), 抽象数据类型方法
 *
 *        Version:  1.0
 *        Created:  07/22/2017 12:00:30 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (LF), wood@khan.ren
 *   Organization:  imau
 *
 * =====================================================================================
 */
#include "DataADT.h"
#include "FatalError.h"

typedef struct file_date {
    unsigned int day: 5;
    unsigned int month: 4;
    unsigned int year: 7;
} Bit_Date;

typedef union int_date {
    unsigned short i;
    struct file_date fd;
} Union_Date;

union reg_date {
    // 针对16位寄存器位域存储
    struct {
        WORD ax, bx, cx, dx;            // 对应x86处理器AX, BX, CX, DX寄存器
    } word;

    // 针对8位寄存器位域存储
    struct {
        BYTE al, ah, bl, bh, cl, ch, dl, dh;    // 对应x86处理器(AL, AH), (BL, BH), (CL, CH), (DL, DH)8位寄存器
    } byte;
} regs;

// 打印位域中文件日期数据
void Print_Date(unsigned short n) {
    Union_Date u;

    u.i = n;
    printf("%d/%d/%d\n", u.fd.month, u.fd.day, u.fd.year + 1980);
}

void Demo_Reg(void)
{
    regs.byte.ah = 0x12;
    regs.byte.al = 0x34;
    printf("AX: %hx\n", regs.word.ax);
}
