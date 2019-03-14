#!/bin/bash

dpkg -s gnuplot &> /dev/null

if [ $? -eq 0 ]; then
    echo "
    "
    echo "Gnuplot ist installiert!"
else
    echo "
    "
    echo "Gnuplot ist noch nicht installiert, möchte Sie dies jetzt tun? (y/n) "
    read ANTWORT
    if [ "$ANTWORT" == "y" ]; then
    sudo apt install gnuplot -y
    fi
fi

dpkg -s build-essential &> /dev/null

if [ $? -eq 0 ]; then
    echo "
    "
    echo "C++ ist installiert!"
else
    echo "
    "
    echo "C++ ist noch nicht installiert, möchte Sie dies jetzt tun? (y/n) "
    read ANTWORT
    if [ "$ANTWORT" == "y" ]; then
    sudo apt install build-essential -y
    fi
fi

echo "

     "
echo -e "Pipeplanner wird nun gebaut."
echo "
     "

make
sleep 1
make clean

echo "

     "
echo "Führen Sie ./pipeplanner aus, um das Programm zu starten."
echo "
     "
