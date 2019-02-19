#!/bin/bash

path=`pwd`
length=(0 0 0)
string=(0 0 0)
file=(0 0 0)
files=`find $path -name "*" -type f`

function storelong() {
    str=$1
    name=$2
    strnum=${#str}
    for i in `seq 0 2`;do
        if [[ strnum -ge length[$i]  ]];then
            for j in `seq 2 -1 $i`;do
                length[$j]=${length[$j-1]}
                file[$j]=${file[$j-1]}
                string[$j]=${string[$j-1]}
            done
            length[$i]=$strnum
            filename[$i]=$name
            string[$i]=$str
            break
        fi
    done 
    #if [[ $strnum -gt ${length[0]} ]]; then
    #    for i in `seq 2 1`; do
    #        length[$i]=${length[$[$i - 1]]}
    #        file[$i]=${file[$[$i - 1]]}
    #        string[$i]=${string[$[$i - 1]]}
    #        if [[ ${$[$i - 1]} -eq 1 ]]; then 
    #            length[${$[$i - 1]}]=$strnum
    #            file[${$[$i - 1]}]=$name
    #            str[${$[$i - 1]}]=$str
    #        fi 
    #    done
    #fi
}

for i in $files; do
    file $i | grep text > /dev/null
    if [[ $? -eq 0 ]]; then
        lstr=`awk 'BEGIN{RS="[\n ]"}{if (length(max)<length()) max=$0}END{print max}' $i` 
        #lstr=`awk 'BEGIN{RS="[\n]"}{if(length(max)<length())max=$0}END{print max}'$i`
        storelong ${lstr} $i
    fi
done

for i in `seq 0 2`; do
    echo ${length[$i]}----${file[$i]}----${string[$i]}
done
