#!/bin/bash
if [ -f "strucitfe" ]
then
	echo "--- CORRECT TESTS ---"
	success=""
	for file in $(ls ../tests/correct/)
	do
		success=$(./strucitfe ../tests/correct/$file 2>&1)
		if [[ "$success" == *"segmentation"* ]]
		then
			echo "-!--------------------!-"
			echo $file
		fi
		success=""
	done
	echo "Success."
	echo "--- INCORRECT TESTS ---"
	success=""
	for file in $(ls ../tests/incorrect/)
  do
		success=$(./strucitfe ../tests/incorrect/$file 2>&1)
		if [[ "$success" == *"segmentation"* ]]
		then
			echo "-!--------------------!-"
			echo $file
			echo $file
		fi
		success=""
  done
	echo "Success."
	echo "-----------------------"
fi
