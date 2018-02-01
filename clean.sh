#!/bin/bash

echo "clean.sh: Starting the purging of unworthy files..."

echo "Removing build directory..."
rm -rf build > /dev/null 2>&1

echo "Removing executables..."
rm FRCOpt FRCDebug FRCUserProgram > /dev/null 2>&1

exit
