/*
 * =====================================================================================
 *
 *       Filename:  union.c
 *
 *    Description:  联合的使用
 *
 *        Version:  1.0
 *        Created:  07/16/2017 06:44:23 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (LF), wood@khan.ren
 *   Organization:  imau
 *
 * =====================================================================================
 */
#include <stdio.h>

#define TITLE_LEN 50
#define AUTHOR_LEN 30
#define DESIGN_LEN 50

struct catalog_item {
    int stock_number;
    double price;
    int item_type;
    union {
        struct {
            char title[TITLE_LEN + 1];
            char author[AUTHOR_LEN + 1];
            int num_pages;
        } book;
        struct {
            char design[DESIGN_LEN + 1];
        } mug;
        struct {
            char design[DESIGN_LEN + 1];
            int colors;
            int sizes;
        } shirt;
    } item;
};
