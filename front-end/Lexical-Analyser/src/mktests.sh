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
                ./LA ../tests/incorrect/$file
        done
        echo "-----------------------"
fi

