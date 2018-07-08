#!/usr/bin/env python
# -*- coding: utf-8 -*-

months = ['January','February','March','April','May','June','July','August','September','October','November','December']

# 以1-31的数字作为结尾的列表
endings = ['st', 'nd', 'rd'] + 17 * ['th'] \
        + ['st', 'nd', 'rd'] + 7 * ['th'] \
        + ['st']

year = input("Year: ")
month = input("Month(1-12): ")
day = input("Day(1-31): ")

month_number = int(month)
day_number = int(day)

# 记得要将月份和天数减1, 以获得正确的索引
month_name = months[month_number - 1]
ordinal = day + endings[day_number - 1]

print(month_name + ' ' + ordinal + ', ' + year)
