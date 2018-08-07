#!/usr/bin/env python
#-*- coding:utf-8 -*-

# (普通递归)oridinary recursive
def fact_normal(n):
    if n == 1:
        return 1
    return n * fact_normal(n-1)


# 尾递归优化(Tail recursion optimization)
def fact(numbers):
    return fact_iter(numbers, 1)

def fact_iter(num, product):
    if  num == 1:
        return product
    return fact_iter(num-1, num*product)
