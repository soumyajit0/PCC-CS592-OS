#!/bin/bash
read -p "Enter a word to check for its occurences : " word
echo "The no. of occurences of $word in the file are : "
grep -c "$word" file.txt
echo
echo "The no. of occurences of $word in the file after ignoring cases are : "
grep -i -c "$word" file.txt
