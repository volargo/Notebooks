#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""关于字典的使用"""

'''先利用列表建立数据库的索引'''
names = ['Khan', 'Lisa', 'Bob', 'Alice']
# 注意如果是整数8进制使用0开头标识,所以列表使用字符串
numbers = ['2040', '2052', '8888', '0192']
print(numbers[names.index('Khan')])

'''一起来使用字典建立索引吧'''
phonebook = {'Alice': '2341', 'Khan': '2040', 'Lisa': '8686'}
print(phonebook['Lisa'])

# 基本字典操作
print(len(dic))     # 返回字典中项(键-值对)的数量
print(dic['name'])
dic['name'] = 'Lisa'    # 关联键值
print(dic['name'])
del dic['age']    # 删除键值
print(dic)
if 'name' in dic:   # 检查是否含有对应键的值
    print("has...")
else:
    pass
