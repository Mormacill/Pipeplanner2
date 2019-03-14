#!/bin/bash

dpkg -s gnuplot &> /dev/null

if [ $? -eq 0 ]; then
    echo "Gnuplot ist installiert!"
else
    echo "Gnuplot ist noch nicht installiert, möchte Sie dies jetzt tun? (y/n)"
    read
    if "$REPLY" = "y"; then
    sudo apt install gnuplot
fi

dpkg -s c++ &> /dev/null

if [ $? -eq 0 ]; then
    echo "C++ ist installiert!"
else
    echo "C++ ist noch nicht installiert, möchte Sie dies jetzt tun? (y/n)"
    read
    if "$REPLY" = "y"; then
    sudo apt install build-essential
fi

echo -e "Pipeplanner wird nun gebaut."

make
sleep 1
make clean
