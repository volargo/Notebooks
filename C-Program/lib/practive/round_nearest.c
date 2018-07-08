/*
 * =====================================================================================
 *
 *       Filename:  round_nearest.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/03/2017 05:05:22 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (imau), wood@khan.ren
 *   Organization:  zy.imau.edu.cn
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <math.h>

double round_nearest(double x, int n) {
    double power = pow(10.0, n);

    if (x < 0.0) {
        return ceil(x * power - 0.5) / power;
    } else {
        return floor(x * power + 0.5) / power;
    }
}
