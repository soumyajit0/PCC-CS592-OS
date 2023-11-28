#!/bin/bash
sort -g file.txt > tmp.txt
mv tmp.txt file.txt
cat file.txt
