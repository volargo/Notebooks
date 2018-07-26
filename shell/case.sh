#!/bin/bash -
#===============================================================================
#
#          FILE: case.sh
#
#         USAGE: ./case.sh
#
#   DESCRIPTION: 
#
#       OPTIONS: ---
#  REQUIREMENTS: ---
#          BUGS: ---
#         NOTES: ---
#        AUTHOR: YOUR NAME (), 
#  ORGANIZATION: 
#       CREATED: 03/23/2018 12:13:37 AM
#      REVISION:  ---
#===============================================================================

set -o nounset                                  # Treat unset variables as an error

echo "input numbers(1~4)"
echo "the number is:"
read aNum

case ${aNum} in
    1) echo "choose 1"
        ;;
    2) echo "choose 2"
        ;;
    3) echo "choose 3"
        ;;
    4) echo "choose 4"
        ;;
    *) echo "wrong choice"
        ;;
esac
