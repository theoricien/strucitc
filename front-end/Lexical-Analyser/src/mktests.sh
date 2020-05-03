#!/bin/bash
if [ -f "LA" ]
then
	echo "--- CORRECT TESTS ---"
	success=""
	for file in $(ls ../tests/correct/)
	do
		success=$(./LA ../tests/correct/$file)
		if [[ "$success" == *"Invalid"* ]]
		then
			echo "-!--------------------!-"
			echo $file
			echo $success;
			exit 2
		fi
		success=""
	done
	echo "Success."
	echo "--- INCORRECT TESTS ---"
	success=""
	for file in $(ls ../tests/incorrect/)
  do
		success=$(./LA ../tests/incorrect/$file)
		if [[ "$success" == *"Success"* ]]
		then
			echo "-!--------------------!-"
			echo $file
			echo $success;
			exit 2
		fi
		success=""
  done
	echo "Success."
	for file in $(ls ../tests/eascii/)
	do
		echo "-----------------------"
		echo "--- EXTENDED ASCII TESTS ---"
		while IFS= read -r line
		do
			echo $line > /tmp/tests
			#./LA /tmp/tests
			if ./LA /tmp/tests | grep -q 'Success'
			then
				echo "Invalid Lexic: \"$line\" in $file"
				hexdump /tmp/tests
				echo "-!-------------------!-"
				exit 2
			fi
			rm /tmp/tests
		done < ../tests/eascii/$file
		echo "Success."
	done
	echo "-----------------------"
fi
