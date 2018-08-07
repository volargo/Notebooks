/*
 * =====================================================================================
 *
 *       Filename:  FatalError.h
 *
 *    Description:  错误处理静态库
 *
 *        Version:  1.0
 *        Created:  07/27/2017 08:04:47 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (), wood@khan.ren
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
