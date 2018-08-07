#!/bin/bash

# 使用open或者create创建已经存在的文件,
# 则其原来的访问权限位不会改变
touch foo bar
ls -l foo bar
./4_4 foo bar
ls -l foo bar
