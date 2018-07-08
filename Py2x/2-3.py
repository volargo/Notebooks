#!/usr/bin/env python
# -*- coding: utf-8 -*-

# 以正确的宽度在居中的"盒子"内打印一个句子

# 整数除法(//)只能在python2.2及后续版本中使用, 之前的版本只能使用普通除法

sentence = input("Sentence: ")

screen_width = 80
text_width = len(sentence)
box_width = text_width + 6
left_margin = (screen_width - box_width) // 2

print(' ' * left_margin + '+' + '-' * (box_width - 2) + '+')
print(' ' * (left_margin) + '| ' + ' ' * text_width + ' |')
print(' ' * (left_margin) + '| ' + sentence + ' |')
print(' ' * (left_margin) + '| ' + ' ' * text_width + ' |')
print(' ' * left_margin + '+' + '-' * (box_width - 2) + '+')
