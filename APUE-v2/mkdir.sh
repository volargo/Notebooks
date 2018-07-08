#!/bin/bash -
#===============================================================================
#
#          FILE: mkdir.sh
#
#         USAGE: ./mkdir.sh
#
#   DESCRIPTION: Batch create the directory
#
#       OPTIONS: ---
#  REQUIREMENTS: ---
#          BUGS: ---
#         NOTES: ---
#        AUTHOR: YOUR NAME (), 
#  ORGANIZATION: 
#       CREATED: 03/21/2018 05:24:16 PM
#      REVISION:  ---
#===============================================================================

set -o nounset                                  # Treat unset variables as an error

mkdir -p ~/notebooks/apue/{5..12}chapter
