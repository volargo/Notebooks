/*
 * =====================================================================================
 *
 *       Filename:  conuterADT.h
 *
 *    Description:  文本内容转换抽象数据类型(ADT)
 *
 *        Version:  1.0
 *        Created:  07/30/2017 05:58:40 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (imau), wood@khan.ren
 *   Organization:  zy.imau.edu.cn
 *
 * =====================================================================================
 */
#ifndef COUNTERADT_H
#define COUNTERADT_H

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define Error(str) FatalError(str)
#define FatalError(str) (fprintf(stderr, "%s\n", str), exit(EXIT_FAILURE))

// 统计字符数量
int count_char(FILE *stream, int n);
// 统计单词数量
int count_word(FILE *stream, int n);
// 统计行的数量
int count_line(FILE *stream, int n);
// 检测文件流错误
int is_error(FILE *stream);
// 打印统计信息
void print_info(FILE *stream, int n);

#endif
