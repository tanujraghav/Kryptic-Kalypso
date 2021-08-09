#!/usr/bin/env bash

function run(){
    echo -e "assets/demo/$1.png\n138bC\n10 29 38\n12 23 34 45 56 67 78 89 90 9 98 87 76 65 54 43 32 21 100 18" | time python3 main.py 2> test >/dev/null
    echo "`cat test | head -n1 | cut -d' ' -f3 | cut -d'e' -f1`"
}

echo > data

for j in 64 128 256 512 1024 2048 4096
do
    for i in 0 1 2 3 4 5 6 7 8 9
    do
        run $j >> data
    done
done

rm -rf "test"