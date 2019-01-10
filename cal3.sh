#!/bin/bash

# Systems Programming - Lab 3
# Devante Wilson - 100554361
# Shahrukh Zarir - 100489271
# October 25, 2016
#
# Task2
# 1. When there is no argument,
# display "You must provide at least one month".
#
# 2. When there is one argument,
# display the calendar of the specified month".
#
# 3. When there are two arguments,
# display the calendar of the 1st argument's month
# and state that the 2nd argument is not a valid
# month/input.

if [ $# -eq 0 ]
	then
	echo "You must provide at least one month."
elif [ $# -eq 1 ]
	then
	cal $1 2016
elif [ $# -eq 2 ]
	then
	cal $1 2016
	echo "$2 is not a valid month/input."
else # [ $# -gt 2 ]
	echo "Enter only a maximum of 2 arguments."
fi   
