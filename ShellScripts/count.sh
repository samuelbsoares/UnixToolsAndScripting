#!/bin/sh

# PROBLEM: Output the numbers from 10 to 500 (inclusive) on one line with spaces 
# between them (and a newline at the end) using:
# a) a for loop (use seq)
# b) a while loop (use a counter)

echo "Using for loop and seq:"
out=""
for i in $(seq 10 500)
do
  out=$out" "$i
done
echo $out

echo "Using while loop and a counter:"
out=""
counter=10
while [ $counter -lt 501 ]
do
  out=$out" "$counter
  counter=$(( $counter + 1 ))
done
echo $out
