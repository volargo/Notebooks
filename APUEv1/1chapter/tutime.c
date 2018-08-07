/*
 * =====================================================================================
 *
 *       Filename:  tutime.c
 *
 *    Description:  test utime function
 *
 *        Version:  1.0
 *        Created:  08/17/2017 09:58:03 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (Loong), urloong@163.com
 *   Organization:  zy.imau.edu.cn
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <errno.h>
#include <utime.h>
#include <fcntl.h>
#include <sys/stat.h>

#define MAXLINE 4096

static void err_doit(int, int, const char *, va_list);
void err_ret(const char *, ...);

int
main(int argc, char *argv[])
{
    int             i, fd;
    struct stat     statbuf;
    struct utimbuf  utimebuf;

    for (i = 1; i < argc; i++) {
        if (stat(argv[i], &statbuf) < 0) {  /* fetch current times */
            err_ret("%s: stat error", argv[i]);
            continue;
        }
        if ((fd = open(argv[1], O_RDWR | O_TRUNC)) < 0) {
            err_ret("%s: open error", argv[i]);
            continue;
        }
        close(fd);
        utimebuf.actime = statbuf.st_atime;
        utimebuf.modtime = statbuf.st_mtime;
        if (utime(argv[i], &utimebuf) < 0) {        /* reset times */
            err_ret("%s: utime error", argv[i]);
            continue;
        }
    }
    exit(0);
}

static void
err_doit(int errorflag, int error, const char *fmt, va_list ap) {
    char        buf[MAXLINE];

    vsnprintf(buf, MAXLINE, fmt, ap);

    if (errorflag) {
        snprintf(buf+strlen(buf), MAXLINE-strlen(buf), ": %s", strerror(error));
    }
    strcat(buf, "\n");
    fflush(stdout);
    fputs(buf, stderr);
    fflush(NULL);
}

void
err_ret(const char *fmt, ...) {
    va_list     ap;

    va_start(ap, fmt);
    err_doit(1, errno, fmt, ap);
    va_end(ap);
}

/* Test way:
 * ----------------------------------------------------------------------
 *  eg1 $: touch changemod      # 创建文件后等待1分钟再创建另一个测试文件
 *      $: touch times          # 创建新的测试文件
 *      $: ls -l changemod times    # 查看长度和最后修改时间
 *      $: ls -lu changemod times   # 查看最后访问时间
 *      $: date                     # 查看当前系统时间
 *      $: ./a.out changemod times  # 运行程序修改文件时间信息
 *      $: ls -l changemod times    # 查看长度和最后修改时间
 *      $: ls -lu changemod times   # 查看最后访问时间
 *      $: ls -lc changemod times   # 检查更改状态时间
 * ----------------------------------------------------------------------*/
