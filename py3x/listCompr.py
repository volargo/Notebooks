#!/usr/bin/python3
#-*- coding:utf-8 -*-

# 列表生成式(List comprehensions)
def list_comprehensions():
    L = [x * x for x in range(1, 11)]
    print(L)

# 使用列表生成式(how to use list comprehensions)
def use_list_comp():
    L = [x * x for x in range(1, 20) if x % 2 == 0]
    print(L)

# 通过列表生成式使用双层循环生成全排列
def full_array():
    L = [m + n for m in 'ABC' for n in 'XYZ']
    print(L)

# 列出当前目录下的所有文件(List all files of the current directory)
import os
files_list = [d for d in os.listdir('.')]
print(files_list)

# 列表生成式使用多个变量生成列表(use two variables generate list-comprehensions)
def do_list(list_name):
    temp_list = [k + '=' + v for k, v in list_name.items()]
    print(temp_list)
L = {'a':'X', 'b':'Y', 'c':'Z'}
do_list(L)

# 列表生成式转换小写
def do_lower(argument):
    if isinstance(argument, list) is False:
             return 0
    else:
        lower_list = [s.lower() for s in argument if isinstance(s, str) is True]
        print(lower_list)
# Test do_lower
test_list = [91.2, 'Hola', 'Sunflower', 'Girl', 'Vibe', 123]
do_lower(test_list)
