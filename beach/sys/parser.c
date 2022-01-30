#include "parser.h"

#include <stdio.h>
#include <string.h>
#include "../colors.h"

int parse_file(char *file, int silent) {

    // Open the file and get the contents into a buffer
    FILE *fp = fopen(file, "r");
    if (fp == NULL) {
        if (!silent) {
            printf("%s[!]%s There was a problem opening the file.\n", RED, reset);
        }
        return 1;
    }
    char line[256];
    char *buffer = malloc(sizeof(char) * 256);
    int i = 0;
    while (fgets(line, sizeof(line), fp) != NULL) {
        buffer[i] = line[i];
        i++;
    }
    buffer[i] = '\0';
    fclose(fp);

    // Make a folder in /var/tmp/beach/ called work-(file)
    char *workdir = malloc(sizeof(char) * 256);
    sprintf(workdir, "/var/tmp/beach/work-%s", file);
    mkdir(workdir, 0777);

    // Get the first line of the file and check if it starts with the words "git" or "curl"
    // If it starts with git, then we should use git to clone the repo (that is in the second line of the file) into the workdir
    // If it starts with curl, then we should use curl to download the file (that is in the second line of the file) into the workdir
    // Print an error message if the first line of the file does not start with git or curl
    char *firstline = malloc(sizeof(char) * 256);
    strcpy(firstline, buffer);
    char *firstline_split = strtok(firstline, "\n");
    char *firstline_split_split = strtok(firstline_split, " ");
    printf("%s[*]%s First line of the file: %s\n", GRN, reset, firstline_split_split);
    // Check if the first line of the file starts with git or curl
    if (strcmp(firstline_split_split, "git") == 0) {
        // If it starts with git, then we should use git to clone the repo (that is in the second line of the file) into the workdir
        char *secondline = malloc(sizeof(char) * 256);
        strcpy(secondline, buffer);
        char *secondline_split = strtok(secondline, "\n");
        char *secondline_split_split = strtok(secondline_split, " ");
        printf("%s[*]%s Second line of the file: %s\n", GRN, reset, secondline_split_split);
        // Use git to clone the repo into the workdir
        char *git_clone = malloc(sizeof(char) * 256);
        sprintf(git_clone, "git clone %s %s", secondline_split_split, workdir);
        printf("%s[*]%s Cloning the repo into the workdir...\n", GRN, reset);
        system(git_clone);
        printf("%s[*]%s Cloning the repo into the workdir... Done!\n", GRN, reset);
    } else if (strcmp(firstline_split_split, "curl") == 0) {
        // If it starts with curl, then we should use curl to download the file (that is in the second line of the file) into the workdir
        char *secondline = malloc(sizeof(char) * 256);
        strcpy(secondline, buffer);
        char *secondline_split = strtok(secondline, "\n");
        char *secondline_split_split = strtok(secondline_split, " ");
        printf("%s[*]%s Second line of the file: %s\n", GRN, reset, secondline_split_split);
        // Use curl to download the file into the workdir
        char *curl_download = malloc(sizeof(char) * 256);
        sprintf(curl_download, "curl -o %s/%s %s", workdir, file, secondline_split_split);
        printf("%s[*]%s Downloading the file into the workdir...\n", GRN, reset);
        system(curl_download);
        printf("%s[*]%s Downloading the file into the workdir... Done!\n", GRN, reset);
    } else {
        // Print an error message if the first line of the file does not start with git or curl
        printf("%s[!]%s The first line of the file does not start with git or curl.\n", RED, reset);
        return 1;
    }

    // Delete the folder /var/tmp/beach/work-(file) if it exists
    char *rm = malloc(sizeof(char) * 256);
    sprintf(rm, "rm -rf %s", workdir);
    system(rm);
}