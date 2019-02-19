#!/bin/bash

msg=$1

MYNAME=`whoami`
MYDATE=`date +%Y.%m.%d`

if [[ $# -ne 1 ]]; then
    echo msg
    exit -1
fi

Dir=/dev/pts/
for pts in $(ls $Dir); do
    echo $MYNAME "this is a wall" $MYDATE $msg >${Dir}/${pts}
done


#宿船长
#User=`logname`
#Time=`date +"%a %b %d %T %Y"`
#Tty=`who am i| awk '{print $2}'`
#Host=`hostname`

#PreMessage="Broadcast massage from $User@$Host ($Tty) ($Time):"

#Message=$1

#for i in `w -h | awk '{print $2}'`; do
#    echo -e "${PreMessage}" >> /dev/$i
#    echo -e "$Message\n\n" >> /dev/$i
#done
