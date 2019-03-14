#!/bin/bash

if ! gnuplot > /dev/null; then
   echo -e "Gnuplot wurde noch nicht auf Ihrem System installiert. Möchten Sie dies jetzt tun? (y/n) \c"
   read
   if "$REPLY" = "y"; then
      sudo apt install gnuplot -y
   fi
fi

if ! c++ > /dev/null; then
   echo -e "C++ wurde noch nicht auf Ihrem System installiert. Möchten Sie dies jetzt tun? (y/n) \c"
   read
   if "$REPLY" = "y"; then
      sudo apt install build-essential -y
   fi
fi

echo -e "Pipeplanner wird nun gebaut."

make
sleep 1
make clean
