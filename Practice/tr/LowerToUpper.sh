#!/bin/bash
tr "[:lower:]" "[:upper:]" < file.txt > tmp.txt
mv tmp.txt file.txt
cat file.txt
