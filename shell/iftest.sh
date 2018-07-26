#!/bin/bash -
#===============================================================================
#
#          FILE: iftest.sh
#
#         USAGE: ./iftest.sh
#
#   DESCRIPTION: 
#
#       OPTIONS: ---
#  REQUIREMENTS: ---
#          BUGS: ---
#         NOTES: ---
#        AUTHOR: YOUR NAME (), 
#  ORGANIZATION: 
#       CREATED: 03/22/2018 11:19:32 PM
#      REVISION:  ---
#===============================================================================

set -o nounset                                  # Treat unset variables as an error

num1=$[2*3]
num2=$[3*3]

if test $[num1] -eq $[num2]; then
    echo "Two Numbers are equal"
else
    echo "Two Number not equal"
fi
