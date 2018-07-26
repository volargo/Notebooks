#!/usr/bin/env python
# -*- coding:utf-8 -*-

people = {
    'Alice': {
        'phone': '13664842040',
        'addr': 'imau'
    },
    'Beth': {
        'phone': '18586176040',
        'addr': 'imau'
    },
    'Lisa': {
        'phone': '17704842040',
        'addr': 'imau'
    }
}

# 针对电话号码何地址使用的描述性标签, 会在打印输出的时候用到
lables = {
    'phone': 'phone number',
    'addr': 'address'
}

name = raw_input("Name: ")

# 查找电话号码还是地址
request = raw_input('Phone number (p) or address (a)?')

# 使用正确的键
if request == 'p':
    key = 'phone'
if request == 'a':
    key = 'addr'

# 如果名字是字典中的有效键值才打印信息
if name in people:
    print("%s's %s is %s" % (name, lables[key], people[name][key]))
