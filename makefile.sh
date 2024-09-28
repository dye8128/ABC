#!/bin/bash

if [ $# -ne 1 ]; then
    echo "Usage: $0 <number>"
    exit 1
fi

number=$1

cd ~/algorithm/ABC

for c in {A..E}; do
    echo "Creating file ./${number}${c}.cpp"
    cp template.cpp "${number}${c}.cpp"
done