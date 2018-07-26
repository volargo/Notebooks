/*
 * =====================================================================================
 *
 *       Filename:  FatalError.h
 *
 *    Description:  错误处理静态库
 *
 *        Version:  1.0
 *        Created:  07/22/2017 12:13:15 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (LF), wood@khan.ren
 *   Organization:  imau
 *
 * =====================================================================================
 */
#ifndef FATALERROR_H
#define FATALERROR_H

#include <stdio.h>
#include <stdlib.h>

#define Error(str) FatalError(str)
#define FatalError(str) (fprintf(stderr, "%s\n", str), exit(EXIT_FAILURE))

#endif
