/*
 * =====================================================================================
 *
 *       Filename:  MS-DOS.c
 *
 *    Description:  MS-DOS操作系统存储文件
 *
 *        Version:  1.0
 *        Created:  07/21/2017 10:24:14 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (LF), wood@khan.ren
 *   Organization:  imau
 *
 * =====================================================================================
 */
// 结构中的位域存储
struct file_date {
    unsigned int day: 5;
    unsigned int month: 4;
    unsigned int year: 7;
};
