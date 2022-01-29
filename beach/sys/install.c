#include "install.h"

#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <fcntl.h>
#include "../colors.h"

// Import a thread library
#include <pthread.h>

void install(int argc, char *args[99], int silent, char *version)
{
    // Check using string.c to see if args[1] is an empty string if it is, then print an error message
    if (strcmp(args[1], "") == 0)
    {
        printf("%s[!]%s No package name was given.\n", RED, reset);
        return;
    }

    printf("\n%s> %sbeach package manager\n\n%s", CYN, GRN, reset);

    // Print all files in /var/beach/pkg to the console
    DIR *dir;
    struct dirent *ent;
    
    // Open the directory
    dir = opendir("/var/beach/pkg/");
    if (dir == NULL)
    {
        printf("%s> %sError: Could not open directory.\n%s", RED, GRN, reset);
        return;
    }

    int found = 0;

    printf("%s> %sAvailable packages:\n%s", CYN, GRN, reset);

    // Read all files in the directory
    while ((ent = readdir(dir)) != NULL)
    {
        // If the file is a directory, skip it
        if (ent->d_type == DT_DIR)
           continue;

        printf("%s> %s%s\n%s", CYN, GRN, ent->d_name, reset);

        // Ignore files that do not end in .build-pkg
        if (strcmp(ent->d_name + strlen(ent->d_name) - strlen(".build-pkg"), ".build-pkg") != 0)
            continue;

        // Print the file name
        //printf("%s> %s%s\n", GRN, ent->d_name, reset);

        // Check if the filename includes the string in char[1] and print it
        if (strstr(ent->d_name, args[1]) != NULL)
        {
            printf("%s> sus > %s%s\n%s", CYN, GRN, ent->d_name, reset);

            // check if version is empty, if it is, then check if the file name includes the version in ent->d_name
            if (strcmp(version, "") == 0)
            {
                printf ("%s> %sChecking version...\n%s", CYN, GRN, reset);
                if (strstr(ent->d_name, version) != NULL)
                {
                    printf("%s> found pkg %s%s\n%s", CYN, GRN, ent->d_name, reset);
                }
            }

            printf("%s> %s%s\n", GRN, ent->d_name, reset);

            //found = 1;
        }
    }

    if(found == 0)
    {
        printf("%s> %sNo packages found.\n%s", RED, GRN, reset);
    }

    // Close the directory
    closedir(dir);

}