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

    // Search through the folder /var/beach/pkg if it includes a file ending in .build-pkg
    // That contains the package name in args[1]
    // And if version is not empty, then check if the version is the same as the version in the file which the filename is formatted as "<package>_<version>.build-pkg"
    // And the version being formatted as "x.x.x"
    // If the version is not the same, then print an error message and return
    // If no version is given, then use the latest version of the file, because there can be multiple versions of the file
    // Once a file is found, then print a message saying the package name, versino and the file path
    // Don't install a package if it is listed in /var/beach/installed
    // If the package is not installed, then install it by opening the file and copying the name to the file /var/beach/installed
    // If the file is not found, then print an error message

    DIR *dir;
    struct dirent *ent;
    char *filename;
    char *package;
    char *version_file;
    char *version_file_version;
    char *version_file_package;

    // Open the directory /var/beach/pkg
    dir = opendir("/var/beach/pkg");

    // If the directory does not exist, then print an error message and return
    if (dir == NULL)
    {
        printf("%s[!]%s The directory /var/beach/pkg does not exist.\n", RED, reset);
        return;
    }

    // Loop through the directory
    while ((ent = readdir(dir)) != NULL)
    {
        // If the file is a .build-pkg file, then
        if (strstr(ent->d_name, ".build-pkg") != NULL)
        {
            // Declare a buffer to store the file name
            filename = ent->d_name;

            // Declare a buffer to store the package name
            package = strtok(filename, "_");

            // Declare a buffer to store the version
            version_file = strtok(NULL, "_");

            // Declare a buffer to store the version
            version_file_version = strtok(version_file, ".");

            // Declare a buffer to store the package name
            version_file_package = strtok(NULL, ".");

            // Parse the version file's version to the correct format "x.x.x"
            version_file_version = strcat(version_file_version, ".");
            version_file_version = strcat(version_file_version, strtok(NULL, "."));
            version_file_version = strcat(version_file_version, ".");
            version_file_version = strcat(version_file_version, strtok(NULL, "."));

            // If the package name is the same as the package name in args[1], then
            if (strcmp(package, args[1]) == 0)
            {
                // If the version is not empty, then
                if (strcmp(version, "") != 0)
                {
                    // Print the version input
                    printf("%s[*]%s Version: %s\n", GRN, reset, version);
                    // Print the file version
                    printf("%s[*]%s File version: %s\n", GRN, reset, version_file_version);

                    // If the version is the same as the version in the file, then
                    if (strcmp(version, version_file_version) == 0)
                    {
                        // Print a message saying the package name, version and the file path
                        printf("%s[*]%s Installing %s version %s from %s\n", GRN, reset, package, version, filename);

                        // Create a string to store the file path
                        char file_path[256];
                        // Add the path /var/beach/pkg to the file_path
                        strcpy(file_path, "/var/beach/pkg/");
                        // Add the file name to the file_path
                        strcat(file_path, filename);

                        // Open the file
                        FILE *fp = fopen(file_path, "r");

                        // If the file does not exist, then print an error message and return
                        if (fp == NULL)
                        {
                            printf("%s[!]%s The file %s does not exist.\n", RED, reset, filename);
                            return;
                        }
                        // Check if the package is already installed which is done by checking if the package in args[1] in the file /var/beach/installed.
                        // by calling the check_installed function
                        // If it is, then print an error message and return.
                        if (check_installed(args[1]) == 1)
                        {
                            printf("%s[!]%s The package %s is already installed.\n", RED, reset, args[1]);
                            return;
                        }
                    }
                }
            }
        }
    }
}