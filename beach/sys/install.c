#include "install.h"

#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <fcntl.h>
#include "../colors.h"

// Import a thread library
#include <pthread.h>

// Create a check_installed function to check if a package is installed
// A package is installed if it is in the /var/beach/installed file
// If the package is not installed, return 0
int check_installed(char *package)
{
    // Declare a file pointer
    FILE *fp;

    // Open the file
    fp = fopen("/var/beach/installed", "r");

    // If the file does not exist, return 0
    if (fp == NULL)
    {
        return 0;
    }

    // Declare a buffer to store the line
    char line[256];

    // Loop through the file
    while (fgets(line, sizeof(line), fp) != NULL)
    {
        // If the package is found in the file, return 1
        if (strstr(line, package) != NULL)
        {
            fclose(fp);
            return 1;
        }
    }

    // Close the file
    fclose(fp);

    // If the package is not found in the file, return 0
    return 0;
}

void install(int argc, char *args[99], int silent, char *version)
{
    // Check using string.c to see if args[1] is an empty string if it is, then print an error message
    if (strcmp(args[1], "") == 0)
    {
        printf("%s[!]%s No package name was given.\n", RED, reset);
        return;
    }

    printf("\n%s> %sbeach package manager\n\n%s", CYN, GRN, reset);

    // Check if the package is already installed which is done by checking if the package in args[1] in the file /var/beach/installed.
    // If it is, then print an error message and return.
    if (check_installed(args[1]) == 1)
    {
        printf("%s[!]%s The package %s is already installed.\n", RED, reset, args[1]);
        return;
    }

    // If the user is not root then print an error message and return
    if (getuid() != 0)
    {
        printf("%s[!]%s You must be root to install packages.\n", RED, reset);
        return;
    }


    // Check if the file in /var/beach/pkg with the name with the format of args[1]_version.build-pkg exists.
    // If it does not, then print an error message and return.
    // If it does, then print it's name and return.
    
    // Make a buffer to store the file name
    char file[256];
    // Add the string /var/beach/pkg to the buffer
    strcat(file, "/var/beach/pkg/");
    // Add the string args[1] to the buffer
    strcat(file, args[1]);
    // Add the string -version to the buffer
    strcat(file, "_");
    // Add the string version to the buffer
    strcat(file, version);
    // Add the string .build-pkg to the buffer
    strcat(file, ".build-pkg");

    if (access(file, F_OK) != -1)
    {
        printf("%s[+]%s The package /var/beach/pkg/%s_%s.build-pkg was found.\n", GRN, reset, args[1], version);
    
        int confirm = 0; 

        // If the silent flag is not set, then ask the user if they want to install the package
        // If not then return
        if (silent == 0)
        {
            printf("%s[?]%s Do you want to install the package? (y/n) ", CYN, reset);
            char answer[2];
            scanf("%s", answer);
            if (strcmp(answer, "y") != 0)
            {
                printf("%s[!]%s The package was not installed.\n", RED, reset);
                return;
            }
            confirm = 1;
            
        } else {
            confirm = 1;
        }

        // if confirm is 1, then print a message saying that the package is being installed
        if (confirm == 1)
        {
            printf("%s[+]%s Installing the package...\n", GRN, reset);

            // Make a buffer to store the contents of the file in /var/beach/pkg/args[1]_version.build-pkg
            char buffer[256];
            // Open the file in /var/beach/pkg/args[1]_version.build-pkg
            FILE *fp = fopen(file, "r");
            // Read the file into the buffer
            fgets(buffer, sizeof(buffer), fp);
            
            // Loop through each line of the buffer and execute the command
            char *line = strtok(buffer, "\n");

            while (line != NULL)
            {
                // Execute the command
                system(line);
                // Read the next line
                line = strtok(NULL, "\n");
            }

            // Close the file
            fclose(fp);

        }
    }
    else
    {
        printf("%s[!]%s The package /var/beach/pkg/%s_%s.build-pkg was not found.\n", RED, reset, args[1], version);
        return;
    }

}