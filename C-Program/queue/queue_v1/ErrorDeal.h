/*
 * =====================================================================================
 *
 *       Filename:  Error_Deal.h
 *
 *    Description:  错误处理静态库
 *
 *        Version:  1.0
 *        Created:  07/17/2017 11:58:45 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (LF), wood@khan.ren
 *   Organization:  imau
 *
 * =====================================================================================
 */
#ifndef _ERROR_DEAL_H
#define _ERROR_DEAL_H

#include <stdio.h>
#include <stdlib.h>

#define Error(str) FatalError(str)
#define FatalError(str) (fprintf(stderr, "%s\n", str), exit(EXIT_FAILURE))

#endif
