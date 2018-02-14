#!/bin/bash

echo "clean.sh: Starting removal..."

cur=`pwd`

dir="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
cd $dir

echo "Removing build directory..."
rm -rf build > /dev/null 2>&1

echo "Removing executables..."
rm FRCOpt FRCDebug FRCUserProgram > /dev/null 2>&1

cd $cur

exit
