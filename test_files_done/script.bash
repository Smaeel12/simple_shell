#!/bin/bash

for file in *.txt
do
	echo "$file"
	echo -n "file   check: "; ./checker.bash ./hsh $file; echo ""
	echo -n "memory check: "; ./checker.bash ./hsh $file; echo ""
	echo ""
done
