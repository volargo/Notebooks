/*
 * =====================================================================================
 *
 *       Filename:  getopt_long.h
 *
 *    Description:  getopt_long ADT
 *
 *        Version:  1.0
 *        Created:  09/19/2017 12:15:57 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (Loong), urloong@163.com
 *   Organization:  zy.imau.edu.cn
 *
 * =====================================================================================
 */
#ifndef _GETOPT_LONG_H
#define _GETOPT_LONG_H

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

void print_usage(FILE *, int, const char*);
void err_sys(const char *, ...);

#endif
