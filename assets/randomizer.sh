#!/bin/bash

if [ $# -ne 2 ]; then
	echo "Invalid number of arguments." 
	echo "Usage : ./randomizer.sh <nbr_generated> <amplitude>."
	exit 1
fi

od /dev/urandom -vAn -N$1 -td$2 | tr -s ' ' | sed -r 's/^.{1}//' | tr ' ' '\n' | awk '!x[$0]++' | tr '\n' ' ' | sed -r 's/.$//'
