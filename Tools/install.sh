#!/bin/sh -e

cmake CMakeLists.txt
make -j
sudo mkdir -p /etc/bomberman
sudo cp bomberman /etc/bomberman
sudo cp libengine.a /etc/bomberman
sudo cp -r assets /etc/bomberman
sudo chmod 755 /etc/bomberman
sudo cp Tools/bomberman /usr/bin
sudo chmod 755 /usr/bin/bomberman