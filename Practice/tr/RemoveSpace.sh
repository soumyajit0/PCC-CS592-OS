#!/bin/bash
tr -d " " < file.txt > tmp.txt
mv tmp.txt file.txt
cat file.txt
