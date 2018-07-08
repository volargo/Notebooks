/*
 * =====================================================================================
 *
 *       Filename:  1.c
 *
 *    Description:  use 'typedef' simplified statement(使用类型定义简化声明)
 *
 *        Version:  1.0
 *        Created:  07/11/2017 04:39:38 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (LF), wood@khan.ren
 *   Organization:  imau
 *
 * =====================================================================================
 */
#if 1
typedef int *Fcn(void);
typedef Fcn *Fcn_ptr;
typedef Fcn_ptr Fcn_ptr_array[10];
Fcn_ptr_array x;
#endif

int *(*x[10])(void);
