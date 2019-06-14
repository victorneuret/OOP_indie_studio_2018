#!/bin/sh


cmake CMakeLists.txt
make
sudo mkdir /etc/bomberman
sudo cp bomberman /etc/bomberman
sudo cp libengine.a /etc/bomberman
sudo cp -r assets /etc/bomberman
sudo ln -s /etc/bomberman/bomberman /usr/bin