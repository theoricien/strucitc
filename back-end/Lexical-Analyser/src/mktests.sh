#!/bin/bash
if [ -f "LA" ]
then
	echo "--- CORRECT TESTS ---"
	for file in $(ls ../tests/correct/)
	do
		echo "-----------------------"
		echo $file
		./LA ../tests/correct/$file
	done
	echo "--- INCORRECT TESTS ---"

	for file in $(ls ../tests/incorrect/)
        do
                echo "-----------------------"
		echo $file
                while IFS= read -r line
		do
			echo $line > /tmp/tests
			#./LA /tmp/tests
			if ./LA /tmp/tests | grep -q 'Success'
			then
				echo "Invalid Lexic: \"$line\" in $file"
				hexdump /tmp/tests
				echo "-----------------------"
				exit 2
			fi
			rm /tmp/tests
		done < ../tests/incorrect/$file
		echo "Success."
        done
        echo "-----------------------"
fi

