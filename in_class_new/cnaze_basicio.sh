#!/bin/bash

# Cassie Naze
# Created 7 Feb 2022
# This script is about basic bash file I/O

touch "agent_smith"

# Create symbolic links
#ln -s agent_smith me_me
#ln -s agent_smith me
#ln -s agent_smith me_too

#Chmod for user read and write only 
chmod og-rw agent_smith
chmod u+rw agent_smith

# This is the permissions list saved to a file
touch smith_list.txt
ls -l > smith_list.txt

wc -l <smith_list.txt