#!/bin/bash
read -p "Enter the Character or Word to be replaced : " ToReplace
read -p "Enter the Character or Word to be replaced with : " ReplaceWith
tr "$ToReplace" "$ReplaceWith" < file.txt > tmp.txt
mv tmp.txt file.txt
cat file.txt
