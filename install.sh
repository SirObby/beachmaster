#! /bin/sh

echo "> Cloning beachmaster.."
mkdir bm
cd bm
git clone https://github.com/SirObby/beachmaster
cd beachmaster
echo "> Building package manager."
cd beach
make