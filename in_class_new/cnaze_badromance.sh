#!/bin/bash

# Created by Cassie Naze
# 16 Feb 2022
# Exploration of bash conditionals

# Part1 
var1="Oh-oh-oh-oh-oh, oh-oh-oh-oh, oh-oh-oh"
var2="Caught in a bad romance"
var3="Ra-ra-ah-ah-ah"
var4="Roma Roma-ma"
var5="Gaga, Ooh la-la"
var6="Want your bad romance"


for(( i=1;i<13;i++ ))
do
    if ( [ $i -eq 1 ] || [ $i -eq 3 ] )
    then
        echo ${var1}
    elif ( [ $i -eq 2 ] || [ $i -eq 4 ] )
    then
        echo ${var2}
    elif ( [ $i -eq 5 ] || [ $i -eq 9 ] )
    then
        echo ${var3}
    elif ( [ $i -eq 6 ] || [ $i -eq 10 ] )
    then
        echo ${var4}
    elif ( [ $i -eq 7 ] || [ $i -eq 11 ] )
    then
        echo ${var5}
    elif ( [ $i -eq 8 ] || [ $i -eq 12 ] )
    then
        echo ${var6}
    fi 
done 

# Part2
while read -r line
do
    if [ "./good_movies.txt" ]
    then
        if [ "$line" == "Halloweentown" ]
        then
            echo ${line} "is movie"
        fi
    fi
done<"good_movies.txt"
