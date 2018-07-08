/*
 * =====================================================================================
 *
 *       Filename:  reciprocal.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/18/2017 10:59:26 AM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Loong-Fei (Loong), urloong@163.com
 *   Organization:  zy.imau.edu.cn
 *
 * =====================================================================================
 */
#include <cassert>
#include "reciprocal.hpp"

double
reciprocal(int i) {
    // i can't equal 0
    assert(i != 0);
    return(1.0/i);
}
