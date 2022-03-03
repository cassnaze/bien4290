#!/bin/bash

# Cassie Naze
# Created 1 March 2022
# This script is for data retrieval to probe the expression sequence of a specific gene

# Prompt the user for the number of microarray points to be read in and processed
echo "Enter a gene name."
read geneName
echo "Chosen gene name is ${geneName}"

# First check to see if the gene name input exists
if grep -q ${geneName} ./microarray/gene_list.txt
then
    echo "Found this gene."

else
    echo "The gene name entered does not exist."
    exit 1
fi

for i in {0..6}
do
    if grep ${geneName} suppressed_genes_${i}.txt
    then
        echo "Time Point ${i}: ${geneName} is suppressed."

    elif grep ${geneName} stationary_genes_${i}.txt
    then
        echo "Time Point ${i}: ${geneName} is stationary."

    elif grep ${geneName} expressed_genes_${i}.txt
    then
        echo "Time Point ${i}: ${geneName} is expressed."
    fi
done


# Then output to the screen the status of the gene for each time pointdf