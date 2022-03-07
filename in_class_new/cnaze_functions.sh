#!/bin/bash

# Cassie Naze
# Created 2 March 2022
# This script is about going over some of the major function that we learned in class

# grep can be case insensitive 

# Download a cpp file from online - go to the raw file link

# I think you could also use -nc to only download once
# wget -nc https://raw.githubusercontent.com/grohde1015/ubiquitous-succotash/4355a39306ac36c1c111cd4e97f3a844c33413b0/Lab1/RohdeG_corr.cpp

# Extract all header files and output them to a file
# grep ".hpp" RohdeG_corr.cpp | sed 's/#include //g' | sed 's/"//g' > header.txt

# Extract the function headers and output to a file
grep "float " RohdeG_corr.cpp | grep "::" | sed 's/{//g' > header.txt

# Determine the namespace and add to the end of the file
grep "::" RohdeG_corr.cpp | sed 's/float //g' | sed 's/ //g' | cut -d ":" -f 1 >> header.txt

# How can we save this stuff to a variable to remove it for the next section 
namespace=$( grep "::" RohdeG_corr.cpp | sed 's/float //g' | sed 's/ ?*//g' | cut -d ":" -f 1 )
# echo $namespace

# Determine the header of all files
# grep "::" RohdeG_corr.cpp | sed 's/float //g' | sed 's/ ?*//g' | cut -c 1- >> header.txt
class=$( grep "::" RohdeG_corr.cpp | sed 's/float //g' | sed 's/ //g' | sed 's/^[^::]*[::]//' | sed 's/://' | cut -d ":" -f 1 | cut -d ";" -f 1 )
echo "Class name: ${class}" >> header.txt
#echo "Class name: " >> header.txt