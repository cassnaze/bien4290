#!/bin/bash

# Cassie Naze
# Created 1 March 2022
# This script is for to calibrate and cluster the microarray data from each timepoint

make all
#cd ~
#mkdir bien4290
#mkdir bien4290/Lab2
#mkdir bien4290/Lab2/microarray

# Prompt the user for the number of microarray points to be read in and processed
echo "How many microarray points do you want to analyze?"
read dataPoints
echo "Chosen number is ${dataPoints}"

# Calibrate the data from each of the seven time points
if [ ${dataPoints} -le 6118 ]
then

    # If this file already exists, delete it so we dont keep overwriting
    if [ "./microarray/log_ratio_input.dat" ]
    then
        echo "Deleting the already existing log ratio input file"
        rm -r "./microarray/log_ratio_input.dat"
    fi

    if [ "./microarray/summary.dat" ]
    then
        echo "Deleting the already existing summary file"
        rm -r "./microarray/summary.dat"
    fi

    touch /home/nazec/bien4290/Lab2/microarray/log_ratio_input.dat

    for i in {0..6}
    do
        # Preprocessed data should be written to output files named as log_ratio_[0-6].dat
        ./nazec_pre_processing.o "./microarray/red_${i}.dat" "./microarray/red_background_${i}.dat" "./microarray/green_${i}.dat" "./microarray/green_background_${i}.dat" "./microarray/log_ratio_${i}.dat" ${dataPoints}
        
        # For each preprocessed dataset, copy the log ratio output to a new file named log_ratio_input.dat
        cat /home/nazec/bien4290/Lab2/microarray/log_ratio_${i}.dat > ./microarray/log_ratio_input.dat

        # Run clustering program
            # Create a summary file that lists the final cluster means and the total number of sup, stat and exp genes
        echo "Time Point ${i}: " >> ./microarray/summary.dat
        ./nazec_k_means.o "./microarray/log_ratio_${i}.dat" >> ./microarray/summary.dat

        touch /home/nazec/bien4290/Lab2/suppressed_genes_${i}.txt
        touch /home/nazec/bien4290/Lab2/stationary_genes_${i}.txt
        touch /home/nazec/bien4290/Lab2/expressed_genes_${i}.txt

        # Copy cluster output files to files whose names correspond to the time point
        cp /home/nazec/bien4290/Lab2/suppressed_genes.txt /home/nazec/bien4290/Lab2/suppressed_genes_${i}.txt
        cp /home/nazec/bien4290/Lab2/stationary_genes.txt /home/nazec/bien4290/Lab2/stationary_genes_${i}.txt
        cp /home/nazec/bien4290/Lab2/expressed_genes.txt /home/nazec/bien4290/Lab2/expressed_genes_${i}.txt

    done
else
    echo "The number of points must not exceed 6118!"
    exit 1
fi


