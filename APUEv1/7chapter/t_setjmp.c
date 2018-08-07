/*
 * =====================================================================================
 *
 *       Filename:  t_setjmp.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/14/2017 05:46:00 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (Loong), urloong@163.com
 *   Organization:  zy.imau.edu.cn
 *
 * =====================================================================================
 */
#include "apue.h"
#include <setjmp.h>

#define TOK_ADD 5

void    do_line(char *);
void    cmd_add(void);
int     get_token(void);

jmp_buf     jmpbuffer;

int
main(void)
{
    char    line[MAXLINE];

    if (setjmp(jmpbuffer) != 0) {
        printf("error");
    }
    while (fgets(line, MAXLINE, stdin) != NULL) {
        do_line(line);
    }
    exit(0);
}

char    *tok_ptr;       /* global poniter for get_token() */

void
do_line(char *ptr) {        /* process line of input */
    int     cmd;

    tok_ptr = ptr;
    while ((cmd = get_token()) > 0) {
        switch(cmd) {
            case TOK_ADD:
                cmd_add();
                break;
        }
    }
}

void
cmd_add(void) {
    int     token;

    token = get_token();
    if (token < 0) {        /* an error has occurred */
        longjmp(jmpbuffer, 1);
    }
    /* reset of processing for this command */
}

int
get_token(void) {
    /* fetch next token line pointer to by tok_ptr */
}
