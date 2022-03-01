#!/bin/bash

# Cassie Naze
# Created 1 March 2022
# This script is for to calibrate and cluster the microarray data from each timepoint

make all

# Prompt the user for the number of microarray points to be read in and processed
echo "How many microarray points do you want to analyze?"
read dataPoints
echo "Chosen number is ${dataPoints}"

# Calibrate the data from each of the seven time points
# Preprocessed data should be written to output files named as log_ratio_[0-6].dat
if [ ${dataPoints} -le 6118 ]
then

    for i in {0..6}
    do
        ./nazec_pre_processing.o "./microarray/red_${i}.dat" "./microarray/red_background_${i}.dat" "./microarray/green_${i}.dat" "./microarray/green_background_${i}.dat" "./microarray/log_ratio_${i}.dat" ${dataPoints}
    done
else
    echo "The number of points must not exceed 6118!"
    exit 1
fi

# For each preprocessed dataset, copy the log ratio output to a new file named log_ratio_input.dat

touch /home/nazec/bien4290/Lab2/microarray/concatData.dat
cat /home/nazec/bien4290/Lab2/microarray/log_ratio_*.dat > concatData.dat

# If this file already exists, delete it so we dont keep overwriting
if [ "./log_ratio_input.dat" ]
then
    echo "Deleting the already existing log ratio input file"
    rm -r "./log_ratio_input.dat"
fi 

touch /home/nazec/bien4290/Lab2/microarray/log_ratio_input.dat
cp ./concatData.dat ./microarray/log_ratio_input.dat


# Run clustering program
./nazec_k_means.o "./microarray/log_ratio_input.dat"

# Copy cluster output files to files whose names correspond to the time point


# Create a summary file that lists the final cluster means and the total number of sup, stat and exp genes

