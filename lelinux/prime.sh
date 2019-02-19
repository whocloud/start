#!/bin/bash
declare -a prime
sum=0
for i in `seq 0 $1`; do
    let prime[$i]=0
done
for i in `seq 2 $1`; do
    if [[ ${prime[$i]} -eq 0 ]]; then
        let ++prime[0]
        let prime[${prime[0]}]=i
    fi
    for j in `seq 1 ${prime[0]}`; do
        if [[ $[ ${prime[$j]} * $i ] -gt $1 ]]; then 
            break
        fi
        let prime[$[ ${prime[$j]} * $i ]]=1
        if [[ $[ $i % ${prime[$j]} ] -eq 0 ]]; then 
            break
        fi 
    done
done
for i in `seq 1 ${prime[0]}`; do
    let sum+=${prime[$i]}
done
echo $sum
