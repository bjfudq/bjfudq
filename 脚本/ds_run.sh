#!/bin/bash
#统计每章阅读、选择、伴随、配对等课程类型个数
s1="证明"
for ((i=1;i<=16;i++))
do
    if [ $i -eq 15 ]; then
        continue
    fi
    #echo chapter$i:
    t1=0
    while read line
    do
        if echo $line | grep $s1 >/dev/null; then
            if echo $line | grep "|" >/dev/null; then
                ((t1++))
            fi
        fi
    done < chapter$i/content.md
    echo $t1
done
exit 0

#写法1：将某几节的课名编号 + t
c=12
for ((i=6;i>=4;i--))
do
    for j in `ls chapter$c/`
    do
        s1=${j%%_*}
        if [ $s1 = $i ]; then
            file=$j
            ss=`expr $i + 1`
            file=${file//$s1/$ss}
            echo "git mv chapter$c/$j chapter$c/$file"
            git mv chapter$c/$j chapter$c/$file
        fi
    done
done
exit 0

#写法2：将某几节的课名编号 + t
for ((i=12;i>=2;i--)); do
    oldfile=`ls ${i}_*`
    newfile=$(($i+1))${oldfile#*$i}
    echo "git mv $oldfile $newfile"
    #git mv $oldfile $newfile
done
exit 0
