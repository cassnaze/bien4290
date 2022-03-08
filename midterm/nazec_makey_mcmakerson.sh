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
    touch makefile
fi

# Check to see that this gets pushed and it worked hehe
echo "# This is the makefile created for the midterm" > makefile




# Generate separate targets for each cpp file in the directory
