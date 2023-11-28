#!/bin/bash
echo "The Lines having the word \"error\" are : "
grep -n "error" file.txt
echo
echo "The Lines having the word \"error\" after ignoring cases are : "
grep -n -i "error" file.txt
