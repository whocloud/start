#!/bin/bash
#cat a.sh | tr -c 'a-zA-Z0-9' ' '
lists=`ls`
ans=0
string=-1
finallfile=-1
add=`pwd`
for j in $lists; do
    str=`cat $j | tr -c 'a-zA-Z0-9' " "`
    #echo $j "------------------------------"
    for i in $str; do
        #echo $i ":" ${#i}
        if [[ ${#i} -gt $ans ]]; then
            ans=${#i}
            string=$i
            finallfile=$j
        fi
    done
done
echo "最终"$string ":" $ans ":" $finallfile ":" $add
