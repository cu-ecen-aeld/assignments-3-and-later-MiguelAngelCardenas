#!/bin/bash
# Finder script for assignment 1
# Author: Miguel Angel Cardenas

if [ -z "$1" ]; then
    echo "Must provide a path parameter"
    exit 1
fi

if [ -z "$2" ]; then
    echo "Must provide a search string parameter"
    exit 1
fi

DIR=$(dirname $1)
if ! [ -d "$DIR" ];
then
    mkdir -p "$DIR"
fi

echo "$2" > "$1"

exit 0
