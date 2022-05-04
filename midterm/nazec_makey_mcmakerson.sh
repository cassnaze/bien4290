#!/bin/bash

# Created by Cassie Naze
# Midterm on 8 March 2022
# Create a makefile
# Script will take in a path to a directory with code files as an argument

# Path for the test data /lab/bien4290/midterm2022/...
# MoreComplicated, Multimain, Simple, Straightforward

# Check to see if the makefile already exists, if it does we dont have to make another one
if [ ".nazec/bien4290/midterm/makefile" ]
    then
        echo "Makefile already exists"
        rm -r "makefile"
        touch "makefile"
else
    touch "makefile"
fi

newPath=$1

# Error check the number of arguments entered 
if [[ ($# -ne 1) ]]
then
    echo "Incorrect number of arguments entered"
    exit 1
fi

# Error check if the directory exists before doing anything else
if [ ! -e $newPath ]
then   
    echo "The path to $newPath does NOT exist"
    exit 1
fi

# Otherwise, do stuff
cd "$1"
echo "New path is: $newPath"

# Check to see that this gets pushed and it worked hehe
    # This will also not change regardless of what the rest does
echo "# This is the makefile created for the midterm" > /home/nazec/bien4290/midterm/makefile
echo "CC = g++" >> /home/nazec/bien4290/midterm/makefile

# Save the file name to a variable
nameOfFile=$(echo "$newPath" | sed "s/.*\///")

# Ok so this part makes an array from the path that is input in the command
readarray -t letsMakeThisWork < <(ls -l | grep ".cpp" | sed 's/[^ ]*[ ]//g' )
echo ${letsMakeThisWork[1]}


# 1. Generate separate targets for each cpp file in the directory
    # nazec_stats.o: nazec_stats.cpp nazec_stats.hpp
	# $(CC) -c $^
# 2. Generate and "all" target which consists of each of the above targets and makes exe
    # Determine where the main file is
    # exe must be the name of the folder with the files
    #grep -Fr "main"
mainFile=$( ls -l | grep ".cpp" | grep -Fr "main" | cut -d ":" -f 1 | grep ".cpp" | sed 's/.cpp//g' )
echo $mainFile

# Go through the array we made earlier to make the targets
for (( i=0;i<${#letsMakeThisWork[@]};i++ ))
do
    # First look for the .cpp files that are not the one with the main
    if [[ " ${letsMakeThisWork[i]} " =~ "cpp" &&  ${letsMakeThisWork[i]}  != $main ]]
    then
        echo -n "${letsMakeThisWork[$i]}" | sed 's/.cpp/.o:/g' >> /home/nazec/bien4290/midterm/makefile
        makeTargets+=( $(echo -n "${letsMakeThisWork[$i]}" | sed 's/.cpp/.o/g') )
        #echo ${makeTargets[i]}
        echo -n "${letsMakeThisWork[$i]}"  >> /home/nazec/bien4290/midterm/makefile

        echo -n " " >> /home/nazec/bien4290/midterm/makefile
        echo "${letsMakeThisWork[$i]}" | sed 's/.cpp/.hpp/g' >> /home/nazec/bien4290/midterm/makefile
        echo -e '\t$(CC) -c $^' >> /home/nazec/bien4290/midterm/makefile
    # Look for the .cpp that are the main
    elif  [[ ${letsMakeThisWork[i]}  == $mainFile ]]
    then
        makeTargets+=( $(echo -n "${letsMakeThisWork[$i]}") )
    fi
    

done


echo "$nameOfFile.o:${makeTargets[*]}" >> /home/nazec/bien4290/midterm/makefile
echo -e '\t$(CC) -c $@ $^' >> /home/nazec/bien4290/midterm/makefile

echo "all:$nameOfFile.o" >> /home/nazec/bien4290/midterm/makefile

# 3. Generate a "clean" target that removes all relevant compilation files
    # This should be correct regardlesss of the if the rest is hardcoded
echo "clean:" >> /home/nazec/bien4290/midterm/makefile
echo -e "\trm -f *.o" >> /home/nazec/bien4290/midterm/makefile
echo -e "\trm -f *.gch" >> /home/nazec/bien4290/midterm/makefile

# 4. Perform a make all and run the exe
#make all
#make clean
cd /home/nazec/bien4290/midterm/
make all