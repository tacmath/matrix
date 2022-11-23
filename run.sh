#!/bin/sh

if [ -e "$1" ]; then
        g++ -std=c++11 "$1"/main.cpp
        ./a.out
        rm ./a.out
else
        echo "A valid argument is needed example :"
        echo "./run.sh ex00"
fi
