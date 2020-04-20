#!/bin/bash
if [ -f "strucitfe" ]
then
	echo "--- CORRECT TESTS ---"
	for file in $(ls ../tests/correct/)
	do
		echo "-----------------------"
		echo $file
		./strucitfe ../tests/correct/$file
	done
	echo "--- INCORRECT TESTS ---"

        for file in $(ls ../tests/incorrect/)
        do
                echo "-----------------------"
                echo $file
                ./strucitfe ../tests/incorrect/$file
        done
        echo "-----------------------"
fi

