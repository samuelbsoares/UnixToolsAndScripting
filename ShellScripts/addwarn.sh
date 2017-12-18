#!/bin/sh

# PROBLEM: For all files (in the current directory) that contain the WORD that is the 
# 1st command line argument, insert the second command line argument on a new line at 
# the head of the file. Print usage and exit with status 4 if not given two args. 
# Exit status 1 is there were no such files. Exit status 2 if any of the files could 
# not be altered. Exit status 0 otherwise.

if [ $# -ne 2 ] ; then
  echo "Usage: $0 WORD WARNING"
  exit 4
else
  FILES=$( egrep -l "$1" $( find . -maxdepth 1 -type f -printf "%f\n" ) )
  [ -z "$FILES" ] && exit 1 # exits if resulting string is empty
  sed -i "1i$2" $FILES
  [ $? -ne 0 ] && exit 2 || exit 0
fi
