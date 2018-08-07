#!/usr/bin/python3.6
#-*- coding: utf-8 -*-

import math

# 用户创建自己的绝对值返回函数
def my_abs_v1(x):
    if x >= 0:
        return x
    else:
        return -x
# 用户创建的绝对值返回函数
def my_abs_v2(x):
    if not isinstance(x, (int, float)):
        raise TypeError('bad operand type')
    if x >= 0:
        return x
    else:
        return -x

# 空函数
def voidfunc():
    pass

# 使用math库设置集合
def move(x, y, setp, angle = 0):
    nx = x + setp * math.cos(angle)
    ny = y + setp * math.sin(angle)
    return nx, ny

# 创建方法计算幂次方值
def power_v1(x, n):
    s = 1
    while n > 0:
        n -= 1
        s *= x
    return s

# 设置函数的默认参数
def power_v2(x, n=2):
    s = 1
    while n > 0:
        n -= 1
        s *= x
    return s

# 使用默认参数
def enroll_v1(name, gender):
    print('name:', name)
    print('gender:', gender)
enroll_v1('Lisa', 'F')

def enroll_v2(name, gender, age=6, city='BeiJing'):
    print('name', name)
    print('gender', gender)
    print('age', age)
    print('city', city)

# add end Version1
def add_end_v1(L=[]):
    L.append('End')
    return L

# add end Version2
def add_end_v2(L=None):
    if L is None:
        L = []
    L.append('End')
    return L

# 用list或者tuple模拟可变参数
def calc_v1(numbers):
    sum = 0
    for n in numbers:
        sum += n*n
    return sum

# 可变参数的使用
def calc_v2(*numbers):
    sum = 0
    for n in numbers:
        sum += n*n
    return sum
#已经有一个list或者tuple,如何使用可变参数
nums = [1, 2, 3]
calc_v2(nums[0], nums[1], nums[2])  #直接传递列表或者元组
calc_v2(*nums) #使用*号传递列表或元组

# 关键字参数, 可以传入必选参数,也接受传入任意个数的关键字参数
def person_v1(name, age, **kw):
    print('name:', name, 'age:', age, 'other:',kw)

person_v1('Kohan', 24, city='BaoTou')
extra = {'city':'Beijing', 'Job':'Enginner'}
person_v1('Jack', 23, **extra)

# 命名关键字参数
def person_v2(name, age, **kw):
    if 'city' in kw:
        # 有city参数
        pass
    if 'job' in kw:
        # 有job参数
        pass
    print('name:', name, 'age:', age, 'other:', kw)

def person_v3(name, age, *, city, job):
    print(name, age, city, job)
person_v3('Jack', 23, 'Beijing', 'Enginner')


"""
def fun(element):   // 必选参数
    pass

def fun(nums = 10): // 默认参数
    pass

def fun(*argc): // 可变参数
    pass

def fun(**kw):  // 关键字参数
    pass

def fun(*, a, b):   // 命名关键字参数
    pass

可变参数不能和命名关键字参数
"""
def f1(a, b, c = 0, *args, **kw):
    print('a=',a, 'b=',b, 'c=',c, 'args=', args, 'kw=', kw)

def f2(a, b, c=0, *, d, **kw):
    print('a=',a, 'b=',b, 'c=',c, 'd=',d, 'kw=',kw)
