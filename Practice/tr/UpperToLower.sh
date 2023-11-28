#!/bin/bash
tr "[:upper:]" "[:lower:]" < file.txt > tmp.txt
mv tmp.txt file.txt
cat file.txt
