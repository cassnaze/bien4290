#!/bin/bash

# Pratice midterm from 2021

# There is probably missing data
# When you use bc use a smaller value instead of a really big string to kind of do error checking or figure out where it might be going wrong

# cut will remove the lines that have nothing in them 

# How do we decide the start of a month for the average
# 1. Grab the data column
# 2. Parse out each chunck (motnh,day,year) -> can use cut to cut out the other stuff
# 3. Interested in the difference between months so check to see if (i+1 - i) is 0 or 1 -> if statement
    # Could also check to see if the previous day is greater than the current day

# First step would be to find the country and then remove everything else
# Create subset arrays of the data to make it easier to work with0x
