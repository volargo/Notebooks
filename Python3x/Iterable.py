#!/usr/bin/python3
#-*- coding:utf-8 -*-

# 添加数据对象是否可以迭代的方法
from collections import Iterable

# 迭代(The iteration)
def iteration(argument):
    if isinstance(argument, Iterable) is False:
        return 0
    else:
        if isinstance(argument, dict) is True:
            print('print key of dictionary: ')
            for key in argument:
                print(key)
            print('print value of dictionary: ')
            for value in argument.values():
                print(value)
            print('print key and value of dictionary: ')
            for key, value in argument.items():
                print(key, value)
        elif isinstance(argument, (list, tuple, str)):  # 传入参数是列表,元组,字符串则迭代传入参数
            for val in argument:
                print(val)

# 使用enumerate函数获取下标索引进行迭代
def index_iter(argument):
    if isinstance(argument, Iterable) is True:
        # 使用enumerate函数迭代下标(index)和元素(element)
        for i, value in enumerate(argument):
            print(i, value)
