#!/bin/bash

folder="$1"
count=0

for item in "$folder"/*; do
    if [ -f "$item" ]; then
        count=$((count + 1))
    fi
done

echo "$(basename "$folder") has $count files"