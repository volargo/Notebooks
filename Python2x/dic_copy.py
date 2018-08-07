#!/usr/bin/env python
# -*- coding: utf-8 -*-

'''如果副本中替换值原始字典不受影响, 但是如果修改某个值则原始字典受影响'''
# copy方法返回一个具有相同键-值相对的新字典(浅复制)
x = {'username': 'admin', 'machines': ['foo', 'bar', 'baz']}
y = x.copy()    # 复制一个新字典对象
y['username'] = 'mlh'   # 新字典键值更换
y['machines'].remove('bar')     # 新字典值移除
print(y)    # 打印操作结果
print(x)
