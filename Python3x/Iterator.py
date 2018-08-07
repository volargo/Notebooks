#!/usr/bin/python3
#-*- coding:utf-8 -*-

# 迭代器(Iterator)
from collections import Iterator
from collections import Iterable

def iterator_fun(argu_iterator):
    if isinstance(argu_iterator, Iterator) is True:
        return 'done'
    else:
        return None

# 将可迭代对象转换为迭代器
def to_iterator(argu_iterable):
    if isinstance(argu_iterable, Iterable) is True:
        return iter(argu_iterable)
    else:
        return None
# 测试将可迭代对象转换为迭代器的函数
def test_fun():
    s = to_iterator('ABCDEF')
    print(s)
    if isinstance(s, Iterator) is True:
        print('Iterator')
    else:
        print('Not Iterator')
    for n in s:
        print(n)

# 测试等价于循环的迭代器
def equal_iterator(argu_it):
    if isinstance(argu_it, Iterator):   # 判断传入参数是否为迭代器
        while True:
            try:
                x = next(argu_it)
            except StopIteration as e:  # 迭代器的异常处理
                break
    else:
        print('parameter type Error...')
        return None
