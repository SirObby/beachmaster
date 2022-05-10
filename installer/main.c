#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "prompt.h"

int main(int argc, char const *argv[])
{

    printf("\tWelcome to the Beachmaster installation software. \n\n"); 

    if(argc > 1) {
        for (size_t i = 0; i < argc; i++)
        {
            if(strcmp(argv[i], "+xorg") == 0) {
                goto installation;
            }
        }
        
    }

    if(prompt("Would you like to proceed with the installation?")) {
        if(prompt("Would you like to start an Xorg instance?")) {
            printf("After starting your X instance, open terminal and run ./installer +xorg\n");
            enter(1);
            //system("startx");
            // Disabled for development.
            exit(0);
        }
        installation:
        printf("Wait a moment.\n");
        if(prompt("Do you want to partition your drives?")) {
            char *options_[2] = {"fdisk", "cfdisk"};
            if(options("Select your favoured partitioning tool", options_) == 0) {
                system("fdisk");
            } else {
                system("cfdisk");
            }
        }

    }
    // This program should be run in a live cd, likely by the Beachmaster LiveCD

    return 0;
}