#!/bin/bash
echo "The Email Addresses present in the file are : "
grep -E -o "\b[a-z0-9._]+@[a-z]+.(com|org|in)\b" file.txt
