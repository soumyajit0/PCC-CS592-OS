#!/bin/bash

#Name:Dept:Roll No.

sort -g -t ":" -k3 file.txt > tmp.txt
mv tmp.txt file.txt
cat file.txt
