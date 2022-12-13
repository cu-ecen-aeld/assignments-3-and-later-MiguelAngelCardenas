#!/bin/sh
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

DIR=$1
if ! [ -d "$DIR" ];
then
    echo "$DIR directory does not exist."
    exit 1
fi

NUM_FILES=$(grep -R -l "$2" "$1" | wc -l)
NUM_OCURRENCES=$(grep -R -o "$2" "$1" | wc -l)

echo "The number of files are $NUM_FILES and the number of matching lines are $NUM_OCURRENCES"

exit 0
