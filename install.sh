#! /bin/sh

echo "> Cloning beachmaster.."
mkdir bm
cd bm
git clone https://github.com/SirObby/beachmaster
cd beachmaster
echo "> Building beachmaster packages.."
make
echo "> Select partition. i.e /dev/sda1"
read part
echo "> Trying.. $part"
cd $part
