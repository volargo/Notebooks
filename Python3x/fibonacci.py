#!/usr/bin/python3
#-*- coding:utf-8 -*-

# 使用函数生成斐波那契数列(Fibonacci)
def fibonacci(max):
    n, a, b = 0, 0, 1
    while n < max:
        print(b)
        a, b = b, a + b
        n += 1
    return 'done'

# 包含yield关键字的函数是一个生成器(generator)
def fib(argument):
    n, a, b = 0, 0, 1
    while n < argument:
        yield b
        a, b = b, a+b
        n += 1
    return 'done'
for i in fib(10):
    print(i)

# 通过捕获StopIteration的错误提取返回值
g = fib(6)
while True:
    try:
        x = next(g)
        print('g:', x)
    except StopIteration as e:  # 异常处理
        print("Generator return value", e.value)
        break
