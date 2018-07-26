#!/usr/bin/env python
# -*- coding: utf-8 -*-

# 删除列表的元素
name = ['Khan', 'Lisa', 'Bob']
print(name)
# 删除元素
del name[0]
print(name)

# 列表的分片操作
name = list('KHAN')
print(name)
name[2:] = list('ar')
print(name)
# 列表分片举例
name = list('Perl')
print(name)
name[1:] = list('ython')
print(name)

# 分片在原有元素不替换情况下插入新的元素
numbers = [1, 5]
numbers[1:1] = [2, 3, 4]
print(numbers)
# 举一反三类似可以使用分片赋值删除元素
numbers[1:4] = []
print(numbers)
# 继续举一反三
numbers = [1, 2, 3, 4, 5]
numbers[1:-1] = [0]
print(numbers)
