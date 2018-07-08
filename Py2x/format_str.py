#!/usr/bin/env python
# -*- coding: utf-8 -*-

from math import pi

# 字段宽度和精度
print('%f10' % pi)
print('%10.2f' % pi)
print('%.5s' % 'Guido van Rossum')
# *星号作为字段宽度或者精度
print('%.*s' % (5, 'Guido van Rossum'))
