#!/usr/bin/python3
#-*- coding:utf-8 -*-

# yield关键字generator
def odd():
    print('step 1')
    yield(1)
    print('step 2')
    yield(3)
    print('step 3')
    yield(5)
