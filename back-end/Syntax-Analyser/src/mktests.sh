#!/bin/bash
if [ -f "strucitbe" ]
then
	echo "--- CORRECT TESTS ---"
	for file in $(ls ../tests/correct/)
	do
		echo "-----------------------"
		echo $file
		./strucitbe ../tests/correct/$file
	done
	echo "--- INCORRECT TESTS ---"

        for file in $(ls ../tests/incorrect/)
        do
                echo "-----------------------"
                echo $file
                ./strucitbe ../tests/incorrect/$file
        done
        echo "-----------------------"
fi
