#!/bin/bash -
#===============================================================================
#
#          FILE: for.sh
#
#         USAGE: ./for.sh
#
#   DESCRIPTION: 
#
#       OPTIONS: ---
#  REQUIREMENTS: ---
#          BUGS: ---
#         NOTES: ---
#        AUTHOR: YOUR NAME (), 
#  ORGANIZATION: 
#       CREATED: 03/22/2018 11:28:39 PM
#      REVISION:  ---
#===============================================================================

set -o nounset                                  # Treat unset variables as an error

array=(1 2 3 4 5 A B C D E)

for x in ${array[@]}
do
    echo "The value is: $x"
done

echo "array length is ${#array[@]}"
echo "array length is ${#array[*]}"
echo "one element length is ${#array[1]}"
