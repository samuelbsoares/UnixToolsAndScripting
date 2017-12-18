#!/bin/sh

# PROBLEM: Write a script that, when run, will put an empty file named "Happy Birthday!!!" 
# in a user's home directory on their birthday. The birthdays of users shall be stored 
# in a file called "birthdays.data", one entry per line, where each line is: username 
# month day. eg: alice Nov 3.

FILE=~/bin/birthdays.data
while read -r line; do
  u=$( echo $line | cut -d" " -f1 )
  bday=$( echo $line | cut -d" " -f2- )
  DATE=`date '+%b %d'`
  [ "$bday" = "$DATE" ] && touch "/home/$u/Happy Birthday!!!"
done < $FILE
