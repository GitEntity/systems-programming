#!/bin/bash

# Systems Programming - Lab 3
# Devante Wilson - 100554361
# Shahrukh Zarir - 100489271
# October 25, 2016
#
# Task0
# This shell script allows two arguments
# to be passed into the command line
# which then prints "Hello World".

if [ $# -eq 2 ]
	then
	echo "Hello World"
elif [ $# -eq 1 ]
	then
	echo "Enter one more argument."
elif [ $# -eq 0 ]
	then
	echo "Enter two arguments."
else # [ $# -gt 2 ]
	echo "Enter only two arguments."
fi
