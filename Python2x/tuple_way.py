#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""元组:不可变序列"""

# 逗号分隔一些值即为创建元组
tup = (1, 2, 3)     # 多个元素的元组
print(tup)
oneElem_Tup = (1, )     # 一个元素的元组
print(oneElem_Tup)
none_tup = ()   # 空元组
print(none_tup)

# 正确使用元组需要使用逗号进行分隔以作为创建方法
var = 3 * (42+2,)
print(var)

# 函数创建元组
print(tuple([1, 2, 3]))
print(tuple('abc'))
print((1, 2, 3))

# 元组的分片即是元组
x = 1, 2, 3
print(x[1])
print(x[0:2])
