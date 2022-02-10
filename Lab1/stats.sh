#!/bin/bash

# Cassie Naze
# Created 10 Feb 2022
# This script is for histogram analysis

echo "What concentration level do you want to analyze? (00 or 05)"
read level
echo "Chosen concentration is ${level}"

# Check for a valid file name
if [ ${level} == '00' ] || [ ${level} == '05' ]
then

    # Concatenate all data from the chosen contration into new file in EEG_DATA 
    touch concatData.txt
    cat /home/nazec/bien4290/Lab1/EEG_DATA/ERP${level}/ERP${level}?*.txt > concatData.txt
    mv ./concatData.txt ./EEG_DATA/concatData.txt

    #Copy new data into a file named catted_input.dat
    touch /home/nazec/bien4290/Lab1/catted_input.dat
    cp ./EEG_DATA/concatData.txt ./catted_input.dat

    # Execute the histogram program for the new data set
    g++ -o staty nazec_stats_test.cpp nazec_stats.cpp

    # Write the output of the histogram to a file placed in EEG_DATA
    touch /home/nazec/bien4290/Lab1/EEG_DATA/histo_${level}.txt
    ./staty "./catted_input.dat" > /home/nazec/bien4290/Lab1/EEG_DATA/histo_${level}.txt


    # Print to the screen where the output is stored and verify that is true
    echo "The file is stored here: "
    find $PWD -type f | grep "histo_${level}.txt" 

else
    echo "That was not a valid choice..you suck!"
    exit 1
fi