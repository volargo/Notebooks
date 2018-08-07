#!/bin/bash -
#===============================================================================
#
#          FILE: while.sh
#
#         USAGE: ./while.sh
#
#   DESCRIPTION: 
#
#       OPTIONS: ---
#  REQUIREMENTS: ---
#          BUGS: ---
#         NOTES: ---
#        AUTHOR: YOUR NAME (), 
#  ORGANIZATION: 
#       CREATED: 03/22/2018 11:10:57 PM
#      REVISION:  ---
#===============================================================================

set -o nounset                                  # Treat unset variables as an error

### basic while loop 
int=1

while (( $int <= 5 ))
do
    echo $int
    let "int++"
done

### read keyboard info by while
echo "Press <Ctrl+D> quit"
echo -n "Input website name: "

while read NET_NAME
do
    echo "Yeap, \"${NET_NAME}\" is good website"
done
