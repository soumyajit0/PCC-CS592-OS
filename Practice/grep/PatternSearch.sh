#!/bin/bash
echo "The Lines that start with a Vowel are : "
#grep -E -n -i "^[aeiou]+" file.txt		Method 1
grep -E -n -i "^(a|e|i|o|u)+" file.txt	       #Method 2
