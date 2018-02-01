#!/bin/bash

echo "full.sh: Starting a full deployment of the code..."

clean() {
    echo "full.sh: Cleaning up..."
    ./clean.sh
    exit $1
}

./clean.sh
echo "full.sh: Starting the build..."
./build.sh "$@" ; passing=$?
if [ passing -ne 0 ]; then
    echo "full.sh: Build failed."
    clean 1
else
    echo "full.sh: Starting the deploy..."
    ./deploy.sh ; deployed=$?
    if [ deployed -ne 0 ]; then
        echo "full.sh: Deploy failed."
        clean 1
    fi
fi

clean 0
