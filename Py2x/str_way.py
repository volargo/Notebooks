#!/usr/bin/env python
# -*- coding: utf-8 -*-

# 模板字符串
import string
from string import Template    # 模板字符串方法
from string import maketrans    # 字符转换表

s = Template('$x, glorious $x!')
s = s.substitute(x='slurm')
print(s)

# 如果替换字段是单词的一部分,那么参数名称就必须用括号括起来,从而明确指明结尾
str = Template("It's ${x}tastic!")
str = str.substitute(x='slurm')
print(str)

# 除关键字外使用字典进行替换
str = Template('A $thing must never $action.')
dic = {}
dic['thing'] = 'gentleman'
dic['action'] = 'show his socks'
str = str.substitute(dic)
print(str)

# find方法返回查找字串的最左端索引,没有找到则返回-1,返回值并不是布尔值
print('with a moo-moo here, and a moo-moo there.'.find('moo'))
title = "Monty Python's Flying Circus"
print('%d\n%d' % (title.find('Monty'), title.find('Python')))
print('%d\n%d' % (title.find('Flying'), title.find('Zirquss')))
# 提供起始点和结束点参数
subject = '$$$ Get rich now!!! $$$'
print(subject.find('$$$', 1))
print(subject.find('$$$', 0, 16))

# join方法(添加字符)
seq = ['1', '2', '3', '4', '5', '6']
sep = '+'
print(sep.join(seq))
dirs = '', 'usr', 'bin', 'env'
print('/'.join(dirs))

# lower方法(大写字母转换为小写)
print("I WANT GET YOU, MY GIRL!".lower())   # 将大写字母转换为小写字母
name = 'Gumby'
if name.lower() in ['gumby', 'khan', 'lisa']:
    print('Found it')

# title方法
print("that's all folks".title())
print(string.capwords("that's all. folks"))

# replace方法(字符串替换)
print("This is a test".replace('is', 'eez'))

# split方法(分割字符串)
print('1+2+3+4+5'.split('+'))

# strip方法去除两侧空格的字符串, 或者指定的参数
print('    a little boy    '.strip())
print('hallo, girl!'.strip('!'))

# translate方法处理单个字符
table = maketrans('cs', 'kz')
print("this is an incredible test".translate(table))
