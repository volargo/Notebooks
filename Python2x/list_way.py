#!/usr/bin/env python
# -*- coding: utf-8 -*-

# 追加新的对象到列表的末尾
lst = [1, 2, 3]
lst.append(4)
print(lst)

# 统计某个元素在列表中出现的次数
nums = ['to', 'be', 'or', 'not', 'to', 'be'].count('to')
print(nums)
x = [[1, 2], 1, 1, [2, 1, [1, 2]]]
print(x.count(1))

# 在列表末尾一次性追加另一个序列中的多个值
a = [1, 2, 3]
b = [4, 5, 6]
a.extend(b)
print(a)
# 有别于连接操作,其直接修改列表而非返回新的列表
c = a + b
print(c)
# 分片操作实现序列追加
a = [1, 2, 3]
b = [4, 5, 6]
a[len(a):] = b
print(a)

# 寻找首个匹配项的索引值
knights = ['We', 'are', 'the', 'knights', 'who', 'say', 'ni']
print(knights.index('who'))
# 索引项不存在则抛出异常
# print(knights.index('herring'))

# 将对象插入到列表中
numbers = [1, 2, 3, 4, 5, 7]
numbers.insert(5, 6)
print(numbers)
numbers[0:1] = [0]
print(numbers)

# 移除列表中的一个元素
x = [1, 2, 3]
x.pop()    # pop默认移除最后一个元素, 可以实现数据结构:栈
print(x)
x = [1, 2, 3]
x.append(x.pop())   # 使用append实现入栈
print(x)

# 移除列表中的首个匹配项
x = ['to', 'be', 'or', 'not', 'to', 'be']
x.remove('be')
print(x)

# 序列反向存放
x = [1, 2, 3]
x.reverse()
print(x)

# 序列排序方法
x = [11, 111, 0, 1, -1, 2, 4]
x.sort()    # sort方法会返回空值
print(x)
# sorted方法可以获得排序后的列表副本
x = [4, 6, 2, 1, 7, 9]
y = sorted(x)
print(y)
y.reverse()
print(y)

# 高级排序方法
# print(cmp(42, 32))
# numbers = [5, 2, 9, 7]
# numbers.sort(cmp)
# print(numbers)
# 根据键值来排序
x = ['Khan', 'Bob', 'Byrant', 'Lisa', 'Loong-Fei']
x.sort(key=len)
print(x)
