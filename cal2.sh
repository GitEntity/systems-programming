#!/bin/bash

# Systems Programming - Lab 3
# Devante Wilson - 100554361
# Shahrukh Zarir - 100489271
# October 25, 2016
#
# Task1
# 1. When there is no argument passed in,
# a calendar of the current month and year is printed.
# 
# 2. When there is one argument passed in,
# a calendar with the specified month matching the argument
# is printed.
#
# 3. When there are two arguments passed in,
# a calendar with the specified month and year is printed.

if [ $# -eq 0 ]
	then
	cal
elif [ $# -eq 1 ]
	then
	cal $1 2016
elif [ $# -eq 2 ]
	then
	cal $1 $2
else # [ $# -gt 2 ]
	echo "Enter a maximum of two arguments."
fi   
