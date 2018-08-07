#!/usr/bin/python3
#-*- coding:utf-8 -*-

# 构造一个1, 3, 5, 7, 9, ..., 99的列表
L = []
n = 1
while n <= 99:
    L.append(n)
    n += 2

# 取一个list(列表)或者tuple(元组)的部分元素, 使用切片(Slice)
def slice(n, argument):
    if n > len(argument):
        return 0
    print(argument[:n])

# 切片的用途(The purpose of the slice)
def purpose_of_slice(L):
    L = list(range(1,101))
    print(L[:10])
    print(L[-10:])
    print(L[::5])
    print(L[10:20])
