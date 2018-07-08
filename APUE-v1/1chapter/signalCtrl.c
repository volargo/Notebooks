/*
 * =====================================================================================
 *
 *       Filename:  signal_control.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/07/2017 10:28:13 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (imau), wood@khan.ren
 *   Organization:  zy.imau.edu.cn
 *
 * =====================================================================================
 */
#include "apue.h"
#include <sys/wait.h>

static void sig_int(int);       /* our signal-catching function */

int
main(void)
{
    char    buf[MAXLINE];
    pid_t   pid;
    int     status;

    if (signal(SIGINT, sig_int) == SIG_ERR) {
        err_sys("signal error");
    }

    printf("%% ");      /* print prompt(提示) (print requires %% to ptint %) */
    while (fgets(buf, MAXLINE, stdin) != NULL) {
        if (buf[strlen(buf) - 1] == '\n') {
            buf[strlen(buf) - 1] = 0;  /* replace newline with null */
        }

        // create child process and check pid's variable
        if ((pid = fork()) < 0) {
            err_sys("fork error");
        } else if (pid == 0) {      /* create child process than execute new process(child) */
            execlp(buf, buf, (char *)0);
            err_ret("couldn't execute: %s", buf);
            exit(127);
        }

        /* parent(wait child over) */
        if ((pid = waitpid(pid, &status, 0)) < 0) {
            err_sys("waitpid error");
        }
        printf("%% ");
    }
    exit(0);
}

void
sig_int(int signo) {
    printf("interrupt\n%% ");
}
