#!/bin/bash -
#===============================================================================
#
#          FILE: word.sh
#
#         USAGE: ./word.sh
#
#   DESCRIPTION: 
#
#       OPTIONS: ---
#  REQUIREMENTS: ---
#          BUGS: ---
#         NOTES: ---
#        AUTHOR: YOUR NAME (), 
#  ORGANIZATION: 
#       CREATED: 07/28/2018 01:45:41 PM
#      REVISION:  ---
#===============================================================================

set -o nounset                                  # Treat unset variables as an error

cat words.txt | tr " " "\n" | sed -e '/^$/d' | sort | uniq -c | sort -rn | awk '{print $2,$1}'
