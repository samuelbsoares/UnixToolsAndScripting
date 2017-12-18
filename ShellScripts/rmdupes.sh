#!/bin/sh

# PROBLEM: Write a script that: removes duplicate regular files (files 
# with the same contents) from the files passed as arguments. Retain the
# file with the oldest timestamp. If there is a tie, choose one arbitrarily.

for f1 in $* ; do
  for f2 in $* ; do
    if [ $f1 != $f2 -a -f $f1 -a -f $f2 ] && cmp $f1 $f2 ; then
      [ $f1 -ot $f2 ] && rm $f2 || rm $f1
    fi
  done
done 2> /dev/null 1> /dev/null
