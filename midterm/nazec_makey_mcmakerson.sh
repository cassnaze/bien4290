#!/bin/bash

# Created by Cassie Naze
# Midterm on 8 March 2022
# Create a makefile
# Script will take in a path to a directory with code files as an argument

# Path for the test data /lab/bien4290/midterm2022

if [ "./midterm/makefile" ]
    then
        echo "Makefile already exists"
else
    touch "makefile"
fi

# Check to see that this gets pushed and it worked hehe
echo "# This is the makefile created for the midterm" > makefile
echo "CC = g++" >> makefile


# 1. Generate separate targets for each cpp file in the directory
    # nazec_stats.o: nazec_stats.cpp nazec_stats.hpp
	# $(CC) -c $^

# File input from the command line
#file=$1
#echo $file

# Hardcoding the files to my dir to be able to get something working
#cp -r /lab/bien4290/midterm2022/Straightforward/. /home/nazec/bien4290/midterm/

# Find where the .cpp files are and save those to an array
readarray -t help < <(ls -l | grep ".cpp" | sed 's/[^ ]*[ ]//g')
# echo $help # This prints only the first element

readarray -t noRepeats < <(ls -l | grep ".cpp" | sed 's/[^ ]*[ ]//g' | sed 's/.cpp//g' )
# echo $noRepeats
num=${#noRepeats[@]}

#for i in "${noRepeats[@]}"
for i in {1..3}
do
    echo ${noRepeats[$i]}.o: ${noRepeats[$i]}.cpp ${noRepeats[$i]}.hpp >> makefile
done

# 2. Generate and "all" target which consists of each of the above targets and makes exe
    # Determine where the main file is
    # exe must be the name of the folder with the files
    #grep -Fr "main"

mainFile=$( ls -l | grep ".cpp" | grep -Fr "main" | cut -d ":" -f 1 | grep ".cpp" )
echo $mainFile

# 3. Generate a "clean" target that removes all relevant compilation files

# 4. Perform a make all and run the exe
#make all


