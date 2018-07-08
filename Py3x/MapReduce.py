#!/usr/bin/python3
#-*- coding:utf-8 -*-

# 从库导入reduce函数
from functools import reduce

# 了解和使用map函数
def square(x):  # 计算平方值
    return x*x

def test_map():
    old_generator = map(square, range(1, 11))  # 使用map函数传入新函数作用于列表
    new_list = list(old_generator) # new_list是一个惰性序列, 使用list函数计算整个序列并返回
    even_list = [x for x in new_list if x%2 == 0]   # 列表生成式生成偶数序列
    return even_list    # 返回偶数序列
print(test_map())

# 将传入的数字序列使用map函数转换为字符序列
def to_str(argu_list):
    if isinstance(argu_list, list) is True:     # 检测传入参数是否匹配list类型
        new_list = map(str, argu_list)  # 使用map函数创建一个新的列表生成器
        print(list(new_list))   # 打印序列结果
to_str(range(1, 11))

# 了解和使用reduce函数
def add(x, y):  # 数值累加函数
    return x+y

def test_reduce(argu_fun, argu_list):   # 测试reduce函数
    return reduce(argu_fun, argu_list)  # 对序列所有元素进行运算产生一个结果数值
print(test_reduce(add, range(1, 11)))
