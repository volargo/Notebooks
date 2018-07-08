#!/usr/bin/python3
#-*- coding:utf-8 -*-

# 复习列表生成式
L = [x**2 for x in range(1, 11)]

# 生成器(generator), 一边循环一边计算
# 没有更多的元素则抛出StopIteration的错误
def example_generator(argument):
    if isinstance(argument, list) is False:
        return 0
    else:
        # 创建生成器
        g = (x*2 for x in range(1, 11))
        # 打印10个生成器的值
        for i in range(1, 11):
            # next函数获取generator的下一个返回值
            # 将获取到的值添加到列表
            argument.append(next(g))

def test_fun():
    # Test example_generator
    test_list = []
    example_generator(test_list)
    print(test_list)

# 使用for循环迭代(Iteration)生成器(generator)
def iter_generator(argument):
    iter_g = (x * 2 for x in range(1, 11))
    for i in iter_g:
        print(i)
iter_generator()    # 测试iter_generator函数
