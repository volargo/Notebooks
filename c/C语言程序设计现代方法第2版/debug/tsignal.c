/*
 * =====================================================================================
 *
 *       Filename:  tsignal.c
 *
 *    Description:  tests signals
 *
 *        Version:  1.0
 *        Created:  08/04/2017 01:17:15 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (imau), wood@khan.ren
 *   Organization:  zy.imau.edu.cn
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <signal.h>

void handler(int sig);
void raise_sig(void);

int main(void)
{
    void (*orig_handler)(int);

    printf("Installing handler for signal %d\n", SIGINT);
    orig_handler = signal(SIGINT, handler);    // 中断信号, 跳转处理函数
    raise_sig();   // 触发中断信号

    printf("Changing handler to SIG_IGN\n");
    signal(SIGINT, SIG_IGN);    // 中断信号参数, 忽略信号参数
    raise_sig();

    printf("Program terminters nomally\n");
    return 0;
}

void handler(int sig)
{
    printf("Handler called for signal %d\n", sig);
}

void raise_sig(void)
{
    raise(SIGINT);
}
