#!/bin/bash -
#===============================================================================
#
#          FILE: infiniteLoop.sh
#
#         USAGE: ./infiniteLoop.sh
#
#   DESCRIPTION: 
#
#       OPTIONS: ---
#  REQUIREMENTS: ---
#          BUGS: ---
#         NOTES: ---
#        AUTHOR: YOUR NAME (), 
#  ORGANIZATION: 
#       CREATED: 03/23/2018 12:28:37 AM
#      REVISION:  ---
#===============================================================================

set -o nounset                                  # Treat unset variables as an error

# infinite loop 1
while :
do
    echo "infinite loop"
done

# infinite loop 2
while true
do
    echo "infinite loop"
done

# infinite loop 3
for (( ; ; ))
do
    echo "infinite loop"
done
