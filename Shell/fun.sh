#!/bin/bash -
#===============================================================================
#
#          FILE: fun.sh
#
#         USAGE: ./fun.sh
#
#   DESCRIPTION: 
#
#       OPTIONS: ---
#  REQUIREMENTS: ---
#          BUGS: ---
#         NOTES: ---
#        AUTHOR: YOUR NAME (), 
#  ORGANIZATION: 
#       CREATED: 03/23/2018 11:08:23 PM
#      REVISION:  ---
#===============================================================================

set -o nounset                                  # Treat unset variables as an error

demoFun() {
    echo "this is demo function"
}
echo "------ exec on here ------"
demoFun
echo "------ over on here ------"

funWithReturn() {
    echo "这个函数对输入的两个数字进行相加运算"
    echo "输入第一个数字:"
    read num1
    echo "输入第二个数字:"
    read num2
    echo "两个数字分别是${num1}, ${num2}"
    return $(($num1+$num2))
}
funWithReturn
echo "输入的两个数字之和为 $? !"

funWithArgu() {
    echo "first argument: $1"
    echo "third argument $3"
    echo "sixed argument $6"
    echo "all argument string $*"
}
funWithArgu 1 2 3 4 5 6 7
