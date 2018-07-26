#!/usr/bin/env python
# -*- coding: utf-8 -*-

url = "https://www.google.com"

print('domain: ' + url[12:])
print('inc: ' + url[12:-4])

numbers = range(1, 21)
print(numbers[-3:])

# step is 2
print(numbers[1::2])
# step is -2
print(numbers[-1:0:-2])
