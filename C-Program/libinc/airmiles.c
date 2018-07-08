/*
 * =====================================================================================
 *
 *       Filename:  airmiles.c
 *
 *    Description:  确定航空里程
 *
 *        Version:  1.0
 *        Created:  08/04/2017 09:15:01 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (imau), wood@khan.ren
 *   Organization:  zy.imau.edu.cn
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct city_info {
    char *city;
    int miles;
}City;

int compare_citites(const void *key_ptr, const void *element_ptr);

int main(void)
{
    char city_name[81];
    City *ptr;

    const City mileage[] = {
        {"Berlin",      3965}, {"Buenos Aires",     5297},
        {"Cairo",       5602}, {"Hong Kong",        7918},
    };

    printf("Enter city name: ");
    scanf("%80[^\n]", city_name);
    ptr = bsearch(city_name, mileage, sizeof(mileage) / sizeof(mileage[0]), sizeof(mileage[0]), compare_citites);

    if (ptr != NULL) {
        printf("%s is %d miles from New York City.\n", city_name, ptr->miles);
    } else {
        printf("%s wasn't found.\n", city_name);
    }

    return 0;
}

int compare_citites(const void *key_ptr, const void *element_ptr) {
    return strcmp((char *)key_ptr, ((City *)element_ptr)->city);
}
