#!/bin/bash

resourceDir=input/
outputDir=output/


for file in $resourceDir*;
do
	python3 Flight.py < $file | tee $outputDir/"out_"${file##*/}
done

echo "\nOutput files are located in output/"
