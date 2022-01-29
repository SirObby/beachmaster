#! /bin/bash

# Tell the user that it's downloading the latest version of the installer and compiling it
echo "Downloading the latest version of the installer..."
# Get the latest version of the installer
wget https://raw.githubusercontent.com/SirObby/beachmaster/main/install.c
# Compile the installer
gcc install.c -o install
# Tell the user that the installer is ready to be run
echo "The installer is ready to be run."
# Run the installer
./install