#!/bin/bash
if [ -f "strucitfe" ]
then
	for file in $(ls ../Tests/)
	do
		echo "-----------------------"
		echo $file
		./strucitfe ../Tests/$file
	done
	echo "-----------------------"
fi

