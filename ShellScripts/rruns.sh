#!/bin/sh

FILE=~/runs.count.txt
ex=1
[ -f $FILE ] && eval $(cat $FILE) && ex=0
COUNTER=$(( $COUNTER + 1 ))
echo COUNTER=$COUNTER > $FILE
echo $COUNTER
exit $ex
