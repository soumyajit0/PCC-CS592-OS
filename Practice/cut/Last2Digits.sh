#!/bin/bash

#Roll No.,Name,Department

echo "The last 2 Digits of the Roll No.s of everyone are : "
tail -n +2 file.csv | cut -d "," -f1 | cut -c10,11
