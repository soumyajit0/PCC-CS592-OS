#!/bin/bash
n=$1
echo -n "The Common Log of $n is : "
echo "scale=2;l($n)/l(10)" | bc -l
