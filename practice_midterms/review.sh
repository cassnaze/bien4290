#!/bin/bash

# Practice with arrays

# Pushing the stuff from the text file to the variable
readarray -t cap < "./captain.txt"

# Will return the first element
# echo $cap 

# Will return the ith element
# echo ${cap[2]}

# Loop through to find elements that have certain properties

lookfor="a"
total=0

for ((i=0;i< ${#cap[@]}; i++ ))
do
    # This will only print out the lines that contain an s
    # echo "Does Captain ${cap[$i]} contain an s?"
    # echo ${cap[$i]} | grep "s"

    # The -c will keep a count
    echo "How many captains contain an s?"
    
    howmany=$(echo ${cap[$i]} | grep "$lookfor" -c)

    if [[ $howmany -ne 0 ]]
    then
        echo "$total+$howmany= ?"
        total=$(echo "$total+$howmany" | bc -l)
        echo "$total"
    fi

    # Globbing don't do it this way
    #if [[ *"$lookfor"* ]]
    #then
    #    echo "Found $lookfor"
    #fi


done
