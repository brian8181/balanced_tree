#!/bin/bash

ARCH=$(uname | sed -E "s|(.{6}).*|\1|") # name from beg of uname
echo $ARCH                              # echo

ARCH=$(uname -o) # operating system
echo ${ARCH^^}   # to upper

# if [[ ARCH = "CYGWIN" ]]; then
# 	define CYGWIN=true
# 	echo "CYGWIN"
# fi
