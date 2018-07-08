/*
 * =====================================================================================
 *
 *       Filename:  read_date.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/30/2017 09:22:19 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (imau), wood@khan.ren
 *   Organization:  zy.imau.edu.cn
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int month, year, day;
    char *m[12] = {
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December"
    };

    if (argc != 2) {
        fprintf(stderr, "usage: command date.\n");
        exit(EXIT_FAILURE);
    }
    if ((sscanf(argv[1], "%d-%d-%d", &month, &day, &year)) == 3) {
        fprintf(stdout, "%s %d, %d\n", m[month-1], day, year);
    }
    else if ((sscanf(argv[1], "%d/%d/%d", &month, &day, &year)) == 3) {
        fprintf(stdout, "%s %d, %d\n", m[month-1], day, year);
    }
    else {
        printf("Date specify format error...\n");
    }

    return 0;
}
