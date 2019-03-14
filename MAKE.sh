#!/bin/bash

dpkg -s gnuplot &> /dev/null

if [ $? -eq 0 ]; then
    echo "Gnuplot ist installiert!"
else
    read -p "Gnuplot ist noch nicht installiert, möchte Sie dies jetzt tun? (y/n) " antwort;
    if [$antwort == y]; then
    sudo apt install gnuplot
    fi
fi

dpkg -s build-essential &> /dev/null

if [ $? -eq 0 ]; then
    echo "C++ ist installiert!"
else
    read -p "C++ ist noch nicht installiert, möchte Sie dies jetzt tun? (y/n) " antwort;
    if [$antwort == y]; then
    sudo apt install build-essential
    fi
fi

echo -e "Pipeplanner wird nun gebaut."

make
sleep 1
make clean
