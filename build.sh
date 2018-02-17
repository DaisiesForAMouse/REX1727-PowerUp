#!/bin/bash

cur=`pwd`
echo "build.sh: Starting build process..."

dir="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
cd $dir
rm "FRCUserProgram"
if [ ! -d "build" ]; then
    mkdir build
fi
cd build

echo "build.sh: Generating Makefiles..."
frcmake ..

target="debug"

echo "$#"

if [ "$1" = "-v" ]; then
    if [ $# -eq 2 ]; then
        target=$2
    fi
    make VERBOSE=1 $target
else
    if [ $# -eq 1 ]; then
        target=$1
    fi
    make $target
fi

cd ..

cp $target "FRCUserProgram"

if [ -f "FRCUserProgram" ]; then
    echo "build.sh: Built successfully!"
    exit 0
else
    echo "build.sh: Build failed!"
    exit 1
fi

cd $cur
exit
