#!bin/bash

#Roll No.,Name,Department

echo "The First Name of all the Students are : "
tail -n +2 file.csv | cut -d "," -f2 | cut -d " " -f1
