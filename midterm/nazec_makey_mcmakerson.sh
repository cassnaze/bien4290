#!/bin/bash

# Created by Cassie Naze
# Midterm on 8 March 2022
# Create a makefile
# Script will take in a path to a directory with code files as an argument

# Path for the test data /lab/bien4290/midterm2022/...

if [ "./midterm/makefile" ]
    then
        echo "Makefile already exists"
else
    touch "makefile"
fi

# Check to see that this gets pushed and it worked hehe
    # This will also not change regardless of what the rest does
echo "# This is the makefile created for the midterm" > makefile
echo "CC = g++" >> makefile

# For the first trial of getting this done, I got stuck with input file stuff so I hardcored in some files
# I think the logic would be similar but able to be used for an arbitrary amount of vals with making targets

# 1. Generate separate targets for each cpp file in the directory
    # nazec_stats.o: nazec_stats.cpp nazec_stats.hpp
	# $(CC) -c $^

# Hardcoding the files to my dir to be able to get something working
#cp -r /lab/bien4290/midterm2022/Straightforward/. /home/nazec/bien4290/midterm/

# Find where the .cpp files are and save those to an array
readarray -t help < <(ls -l | grep ".cpp" | sed 's/[^ ]*[ ]//g')
# echo $help # This prints only the first element

readarray -t noRepeats < <(ls -l | grep ".cpp" | sed 's/[^ ]*[ ]//g' | sed 's/.cpp//g' )
# echo $noRepeats

#for i in "${noRepeats[@]}" # Tried to use this to iterate through the num of elements in the array
for i in {1..3}
do
    echo ${noRepeats[$i]}.o: ${noRepeats[$i]}.cpp ${noRepeats[$i]}.hpp >> makefile
    echo "	\$(CC) -c $^" >> makefile
done

# 2. Generate and "all" target which consists of each of the above targets and makes exe
    # Determine where the main file is
    # exe must be the name of the folder with the files
    #grep -Fr "main"

mainFile=$( ls -l | grep ".cpp" | grep -Fr "main" | cut -d ":" -f 1 | grep ".cpp" | sed 's/.cpp//g' )
#echo $mainFile

echo "$mainFile.o: ${noRepeats[1]}.o ${noRepeats[2]}.o ${noRepeats[3]}.o" >> makefile
echo "	\$(CC) -c $@ $^" >> makefile

# 3. Generate a "clean" target that removes all relevant compilation files
    # This should be correct regardlesss of the if the rest is hardcoded
echo "clean:" >> makefile
echo "	rm -f *.o" >> makefile

# 4. Perform a make all and run the exe
#make all
echo "all: $mainFile.o ${noRepeats[1]}.o ${noRepeats[2]}.o ${noRepeats[3]}.o" >> makefile


# -----------------------------------------------
# This is how we would do it from input argument
# File input from the command line -> couldnt get this to work at first
cd "$1"
echo "New path is: '$(pwd)'" 

# Ok so this part makes an array from the path that is input in the command
readarray -t letsMakeThisWork < <(ls -l | grep ".cpp" | sed 's/[^ ]*[ ]//g' )
echo $letsMakeThisWork

readarray -t removeCPP < <(ls -l | grep ".cpp" | sed 's/[^ ]*[ ]//g' | sed 's/.cpp//g' )
echo ${removeCPP}

findMain=$( ls -l | grep ".cpp" | grep -Fr "main" | cut -d ":" -f 1 | grep ".cpp" | sed 's/.cpp//g' )
echo $findMain