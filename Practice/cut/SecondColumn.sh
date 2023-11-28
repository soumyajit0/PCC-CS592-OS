#/bin/bash

#Roll No.,Name,Department

echo "The contents of the Second Column are : "
tail -n +2 file.csv | cut -d "," -f2
