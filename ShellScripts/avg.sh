#!/bin/sh

# PROBLEM: Suppose your input is lines of numbers, separated by spaces. Each line 
# can have any number of numbers. There can be any number of lines. Find the average 
# of all the numbers. Display it to 4 decimals. (Use read and bc)

sum=0
c=0
while read line  || [ -n "$line" ]
do
  for i in $line;
  do
    sum=$(( $sum + $i ))
    c=$(( $c + 1 ))
  done
done < /dev/stdin
echo "scale=4;$sum/$c" | bc
