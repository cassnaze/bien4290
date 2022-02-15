#!/bin/bash

# Cassie Naze
# Created 10 Feb 2022
# This script is for correlation stuff


# Prompt user for the concentration to analyze
echo "What concentration level do you want to analyze? (00 or 05)"
read level
echo "Chosen concentration is ${level}"

# Check for a valid file name
if [ ${level} == '00' ] || [ ${level} == '05' ]
then

    # Use a loop to analyze two consecutive data files
    g++ -o corry nazec_corr_test.cpp nazec_corr.cpp nazec_stats.cpp

    # Create the file the values will go to

    if [ "./conc_corr_${level}.csv" ]
    then
        echo "Deleting the already existing file with that concentration"
        rm -r "./conc_corr_${level}.csv"
    fi 

    touch /home/nazec/bien4290/Lab1/conc_corr_${level}.csv

    # Check what the input was because the file names are a little different
    if [ ${level} == '00' ]  
    then 
        for i in {1..59}
        do
            # echo ERP${level}${i}.txt
            echo -n "${i}vs$((i+1)), " >> conc_corr_${level}.csv
            ./corry "/home/nazec/bien4290/Lab1/EEG_DATA/ERP${level}/ERP${level}${i}.txt" "/home/nazec/bien4290/Lab1/EEG_DATA/ERP${level}/ERP${level}$((i+1)).txt" >> /home/nazec/bien4290/Lab1/conc_corr_${level}.csv
            # printf '%s\n' {1..59} | paste -sd ',' >> conc_corr_${level}.csv
        done

    elif [ ${level} == '05' ]
    then 
        for i in {1..59}
        do
            # echo ERP${level}.${i}.txt
            echo -n "${i}vs$((i+1)), " >> conc_corr_${level}.csv
            ./corry "/home/nazec/bien4290/Lab1/EEG_DATA/ERP${level}/ERP${level}.${i}.txt" "/home/nazec/bien4290/Lab1/EEG_DATA/ERP${level}/ERP${level}.$((i+1)).txt" >> /home/nazec/bien4290/Lab1/conc_corr_${level}.csv
            # printf '%s\n' {1..59} | paste -sd ',' >> conc_corr_${level}.csv
        done
    fi

# Append the output to a file named conc_corr_[concentration value].csv
    # Label and the value should be separate columns

else
    echo "That was not a valid choice..you suck!"
    exit 1
fi