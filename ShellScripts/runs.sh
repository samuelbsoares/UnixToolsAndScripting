#!/bin/sh

# PROBLEM: Write a script that will: display the number of times that the current 
# user has executed the script, inclusive of the current execution. This value should 
# persist across logins. (chmod the file on creation to give a+w, assume directory has 
# appropriate permission).  Exit with status 1 if this was their first time running the 
# script, 0 otherwise.

FILE=~/runs.count.txt
if [ ! -f $FILE ]
then
  COUNTER=1
  echo $COUNTER > $FILE
  ex=1
else
  COUNTER=$(( `cat $FILE` + 1 ))
  echo $COUNTER  > $FILE
  ex=0
fi
echo $COUNTER
exit $ex
