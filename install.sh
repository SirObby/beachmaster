#! /bin/sh

echo "> Cloning beachmaster.."
mkdir bm
cd bm
git clone https://github.com/SirObby/beachmaster
cd beachmaster
echo "> Building beachmaster packages.."
<<<<<<< HEAD
make
echo "> Select partition. i.e /dev/sda1"
read part
echo "> Trying.. $part"
cd $part
=======
make
>>>>>>> 85433a94da06581740b388c2f416ce1383dea164
