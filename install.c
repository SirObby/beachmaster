/**
 * @file install.c
 * @author Sir Obsidian
 * @brief Install.sh will download, compile and run this file.
 * @version 0.1
 * @date 2022-01-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#include <string.h>

/* Defining colors. */

//Regular text
#define BLK "\e[0;30m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define MAG "\e[0;35m"
#define CYN "\e[0;36m"
#define WHT "\e[0;37m"

//Regular bold text
#define BBLK "\e[1;30m"
#define BRED "\e[1;31m"
#define BGRN "\e[1;32m"
#define BYEL "\e[1;33m"
#define BBLU "\e[1;34m"
#define BMAG "\e[1;35m"
#define BCYN "\e[1;36m"
#define BWHT "\e[1;37m"

//Regular underline text
#define UBLK "\e[4;30m"
#define URED "\e[4;31m"
#define UGRN "\e[4;32m"
#define UYEL "\e[4;33m"
#define UBLU "\e[4;34m"
#define UMAG "\e[4;35m"
#define UCYN "\e[4;36m"
#define UWHT "\e[4;37m"

//Regular background
#define BLKB "\e[40m"
#define REDB "\e[41m"
#define GRNB "\e[42m"
#define YELB "\e[43m"
#define BLUB "\e[44m"
#define MAGB "\e[45m"
#define CYNB "\e[46m"
#define WHTB "\e[47m"

//High intensty background 
#define BLKHB "\e[0;100m"
#define REDHB "\e[0;101m"
#define GRNHB "\e[0;102m"
#define YELHB "\e[0;103m"
#define BLUHB "\e[0;104m"
#define MAGHB "\e[0;105m"
#define CYNHB "\e[0;106m"
#define WHTHB "\e[0;107m"

//High intensty text
#define HBLK "\e[0;90m"
#define HRED "\e[0;91m"
#define HGRN "\e[0;92m"
#define HYEL "\e[0;93m"
#define HBLU "\e[0;94m"
#define HMAG "\e[0;95m"
#define HCYN "\e[0;96m"
#define HWHT "\e[0;97m"

//Bold high intensity text
#define BHBLK "\e[1;90m"
#define BHRED "\e[1;91m"
#define BHGRN "\e[1;92m"
#define BHYEL "\e[1;93m"
#define BHBLU "\e[1;94m"
#define BHMAG "\e[1;95m"
#define BHCYN "\e[1;96m"
#define BHWHT "\e[1;97m"

//Reset
#define reset "\e[0m"

int main(int argc, char const *argv[])
{
    // Ask the user if they want to install beachmaster linux or not if they do not then exit
    printf("%s[?]%s Would you like to install beachmaster linux?\n", GRN, reset);
    printf("%s[?]%s Type %sy%ses or %sn%so.\n", GRN, reset, GRN, reset, GRN, reset);
    char answer[2];
    scanf("%s", answer);
    if (strcmp(answer, "y") != 0)
    {
        printf("%s[!]%s Exiting.\n", RED, reset);
        return 0;
    }
    
    // Print the welcome message
    printf("%s[*]%s Welcome to beachmaster linux installer.\n", GRN, reset);
    printf("%s[*]%s This installer will download and install beachmaster linux.\n", GRN, reset);
    // Print the disclaimer
    printf("%s[*]%s This installer is not responsible for any damage done to your system.\n", GRN, reset);
    // Tell the user they can exit the installer at any time by using Ctrl + C
    printf("%s[*]%s Press Ctrl + C to exit the installer.\n", GRN, reset);
    // Print all the current partitions on the system using fdisk
    printf("%s[*]%s Getting all the partitions on the system.\n", GRN, reset);
    printf("%s[*]%s This may take a while.\n", GRN, reset);
    printf("%s[*]%s Please wait.\n", GRN, reset);
    system("fdisk -l");
    // Ask the user to select the partition they want to install to
    printf("%s[?]%s Please select the device you want to install to.\n", GRN, reset);
    printf("%s[?]%s Type the device.\n", GRN, reset);
    char partition[10];
    scanf("%s", partition);
    // Then create the POSIX filesystem on the selected partition by mounting it and then create the necessary directories
    printf("%s[*]%s Creating the POSIX filesystem on the selected partition.\n", GRN, reset);
    printf("%s[*]%s This may take a while.\n", GRN, reset);
    printf("%s[*]%s Please wait.\n", GRN, reset);
    // Check if /mnt/beachmaster exists if not then create it
    if (system("[ -d /mnt/beachmaster ]") != 0)
    {
        system("mkdir /mnt/beachmaster");
    }

    // Mount the selected partition
    // Create a temporary string to hold the command
    char temp[100];
    // Add the command to the temporary string
    strcpy(temp, "mount ");
    // Add the partition to the temporary string
    strcat(temp, partition);
    // Add the command to the temporary string
    strcat(temp, " /mnt/beachmaster");

    // Create the POSIX compliant file structure on the selected partition
    system(temp);
    // Create the directories:
    // /mnt/beachmaster/bin
    // // /mnt/beachmaster/boot
    // /mnt/beachmaster/dev
    // /mnt/beachmaster/etc/beach
    // /mnt/beachmaster/home
    // /mnt/beachmaster/lib
    // /mnt/beachmaster/lib64
    // /mnt/beachmaster/media
    // /mnt/beachmaster/mnt
    // /mnt/beachmaster/opt
    // /mnt/beachmaster/proc
    // /mnt/beachmaster/root
    // /mnt/beachmaster/run
    // /mnt/beachmaster/sbin
    // /mnt/beachmaster/sys
    // /mnt/beachmaster/srv
    // /mnt/beachmaster/tmp
    // /mnt/beachmaster/usr
    // /mnt/beachmaster/var
    // /mnt/beachmaster/var/beach
    // /mnt/beachmaster/var/cache
    // /mnt/beachmaster/var/db
    // /mnt/beachmaster/var/empty
    // /mnt/beachmaster/var/lib
    // /mnt/beachmaster/var/lock
    // /mnt/beachmaster/var/log
    // /mnt/beachmaster/var/run
    // /mnt/beachmaster/var/spool
    // /mnt/beachmaster/var/tmp

    // Make an array for the directories
    char *directories[] = {
        "/mnt/beachmaster/bin",
        "/mnt/beachmaster/boot",
        "/mnt/beachmaster/dev",
        "/mnt/beachmaster/etc/beach",
        "/mnt/beachmaster/home",
        "/mnt/beachmaster/lib",
        "/mnt/beachmaster/lib64",
        "/mnt/beachmaster/media",
        "/mnt/beachmaster/mnt",
        "/mnt/beachmaster/opt",
        "/mnt/beachmaster/proc",
        "/mnt/beachmaster/root",
        "/mnt/beachmaster/run",
        "/mnt/beachmaster/sbin",
        "/mnt/beachmaster/sys",
        "/mnt/beachmaster/srv",
        "/mnt/beachmaster/tmp",
        "/mnt/beachmaster/usr",
        "/mnt/beachmaster/var",
        "/mnt/beachmaster/var/beach",
        "/mnt/beachmaster/var/cache",
        "/mnt/beachmaster/var/db",
        "/mnt/beachmaster/var/empty",
        "/mnt/beachmaster/var/lib",
        "/mnt/beachmaster/var/lock",
        "/mnt/beachmaster/var/log",
        "/mnt/beachmaster/var/run",
        "/mnt/beachmaster/var/spool",
        "/mnt/beachmaster/var/tmp"
    };

    // Create a loop to create the directories
    for (int i = 0; i < 20; i++)
    {
        // Create a temporary string to hold the command
        char temp[100];
        // Add the command to the temporary string
        strcpy(temp, "mkdir /mnt/beachmaster/");
        // Add the directory to the temporary string
        strcat(temp, directories[i]);
        // Create the directory
        system(temp);
    }

    return 0;
}