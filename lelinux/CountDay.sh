#!/bin/bash
s=$1
e=$2
sum=0
for i in `seq 0 $[ $e - 1 ]`; do
    if [[ $[ $[ $s + $i ] % 400 ] -eq 0 && !$[ $[ $s + $i ] % 100 ] -eq 0 ]]; then
        let sum=$sum+366
    elif [[ $[ $[ $s + $i ] % 4 ] -eq 0 && !$[ $[ $s + $i ] % 100 ] -eq 0 ]]; then
        let sum=$sum+366
    elif [[ !$[ $[ $s + $i ] % 4 ] -eq 0 ]]; then
        let sum=$sum+365
    fi
done
echo $sum
