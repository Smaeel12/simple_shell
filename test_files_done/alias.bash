#!/bin/bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 ~/ismail/simple_shell/*.c -o hsh
mv ~/shared_files/*.txt .
./checker.bash ./hsh $1
