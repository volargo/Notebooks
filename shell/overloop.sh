#!/bin/bash -
#===============================================================================
#
#          FILE: overloop.sh
#
#         USAGE: ./overloop.sh
#
#   DESCRIPTION: 
#
#       OPTIONS: ---
#  REQUIREMENTS: ---
#          BUGS: ---
#         NOTES: ---
#        AUTHOR: YOUR NAME (), 
#  ORGANIZATION: 
#       CREATED: 03/23/2018 12:23:06 AM
#      REVISION:  ---
#===============================================================================

set -o nounset                                  # Treat unset variables as an error

while true
do
    echo "enter numbers (1~5): "
    read aNum
    case ${aNum} in
        1|2|3|4|5)
            echo "choose ${aNum}"
        ;;

        *)
            echo "wrong choice"
            #continue
            break
            echo "game over"
        ;;
    esac
done
