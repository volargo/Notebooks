#!/usr/bin/env python
# -*- coding: utf-8 -*-

# 字典clear方法, 原地操作无返回值或者返回值为None, 类似list.sort
d = {}
d['name'] = 'Khan'
d['age'] = 24
print 'before clear: ', d
returned_value = d.clear()
print 'after clear: ', d

# 为何使用clear方法, 第1种情况
x = {}
y = x
x['Key'] = 'value'
print(y)
x = {}
print(y)

# 第二种情况
x = {}  # 空字典
y = x   # 关联到另一个字典
x['Key'] = 'value'
print(y)
x.clear()
print(y)
