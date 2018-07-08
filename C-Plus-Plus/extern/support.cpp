/*
 * =====================================================================================
 *
 *       Filename:  support.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/30/2017 04:18:23 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (Loong), urloong@163.com
 *   Organization:  zy.imau.edu.cn
 *
 * =====================================================================================
 */
#include <iostream>

extern int count;

void
write_extern(void) {
    std::cout << "Count is " << count << std::endl;
}
