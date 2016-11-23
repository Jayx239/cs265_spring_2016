#!/bin/bash

count1=$(tr ' ' '\n' < input/gads.t20070101 | grep ACMC | wc -l)
count2=$(tr ' ' '\n' < output/out_gads.t20070101 | grep to | wc -l)

echo "NUMBER OF FLIGHTS IN MAIN FILE"
echo $count1

echo "NUMBER OF FLIGHTS IN OUTPUT FILE"
echo $count2