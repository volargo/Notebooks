#!/bin/bash -
#===============================================================================
#
#          FILE: ifelse.sh
#
#         USAGE: ./ifelse.sh
#
#   DESCRIPTION: 
#
#       OPTIONS: ---
#  REQUIREMENTS: ---
#          BUGS: ---
#         NOTES: ---
#        AUTHOR: YOUR NAME (), 
#  ORGANIZATION: 
#       CREATED: 03/22/2018 11:11:33 PM
#      REVISION:  ---
#===============================================================================

set -o nounset                                  # Treat unset variables as an error

a=10
b=20

if [ $a == $b ]; then
    echo "a equal b"
elif [ $a -gt $b ]; then
    echo "a greater than b"
elif [ $a -lt $b ]; then
    echo "a less than b"
else
    echo "Not conform to the conditions"
fi
