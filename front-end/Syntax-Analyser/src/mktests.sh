#!/bin/bash
if [ -f "strucitfe" ]
then
	echo "--- CORRECT TESTS ---"
	success=""
	for file in $(ls ../tests/correct/)
	do
		success=$(./strucitfe ../tests/correct/$file 2>&1)
		if [[ "$success" == *"syntax error"* ]]
		then
			echo "-!--------------------!-"
			echo $file
			mv ../tests/correct/$file ../tests/incorrect/$file
		fi
		success=""
	done
	echo "Success."
	echo "--- INCORRECT TESTS ---"
	success=""
	for file in $(ls ../tests/incorrect/)
  do
		success=$(./strucitfe ../tests/incorrect/$file 2>&1)
		if [[ "$success" == *"Success"* ]]
		then
			echo "-!--------------------!-"
			echo $file
			echo $file
			mv ../tests/incorrect/$file ../tests/correct/$file
		fi
		success=""
  done
	echo "Success."
	echo "-----------------------"
fi
