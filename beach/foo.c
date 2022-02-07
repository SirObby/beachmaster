#include "foo.h"

#include <dialog.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>

#define LEN(arr) ((int) (sizeof(arr) / sizeof(arr)[0]))

void bar()
{
    printf("foobar\n");
}

void d() {
    char *modes[] =
    {
        "Current", "Install packages from the current directory",
        "Other", "Install packages from another directory",
        "Floppy", "Install packages from a floppy disk",
        "Remove", "Remove packages that are currently installed.",
        "Upgrade", "Upgrade packages that are currently installed.",
        "List", "List installed packages.",
        "View", "View the contents of a package.",
        "Exit", "Exit the beach"
    };

    init_dialog(stdin, stdout);
    dialog_menu("beach package manager (beach version 0.0.1)", "Choose an option.", 17, 75, 7, LEN(modes) / 2, modes);
    end_dialog();
    char *result = dialog_vars.input_result; 
    printf("%s\n", result);

    if(strcmp(result, "Current") == 0) {
        char msg[5000] = "Your current directory is:\n";
        //strcat(msg, "\n");
        getcwd(msg, sizeof(msg));
        strcat(msg, "\n");

        // Get all the files in the current directory and print them out IF they end in .beach-pkg
        
        DIR *dir;
        struct dirent *ent;
        if ((dir = opendir (".")) != NULL) {
            /* print all the files and directories within directory */
            while ((ent = readdir (dir)) != NULL) {
                if(strstr(ent->d_name, ".beach-pkg") != NULL) {
                    printf("%s\n", ent->d_name);
                    // Read each line in the file /etc/beach/installed and check if filename is in the list
                    // If it is not in the list, print "POGGERS"
                    // If it is in the list, print "NOT POGGERS"
                    FILE *fp;
                    char *line = NULL;
                    size_t len = 0;
                    ssize_t read;
                    fp = fopen("/etc/beach/installed", "r");
                    if (fp == NULL)
                        exit(EXIT_FAILURE);
                    while ((read = getline(&line, &len, fp)) != -1) {
                        if(strstr(line, ent->d_name) != NULL) {
                            printf("%s\n", "POGGERS");
                        } else {
                            printf("%s\n", "NOT POGGERS");
                        }
                    }

                    // Add the filename to the msg string in a new line
                    strcat(msg, ent->d_name);
                    strcat(msg, "\n");
                }
            }
            
        } else {
            /* could not open directory */
            perror ("");
            return;
        }
        closedir (dir);

        init_dialog(stdin, stdout);
        dialog_msgbox("beach package manager (beach version 0.0.1)", msg, 17, 75, 7);
        end_dialog();
    }
    else if(strcmp(result, "Other") == 0) {

    }
    else if(strcmp(result, "Floppy") == 0) {

    }
    else if(strcmp(result, "Remove") == 0) {

    }
    else if(strcmp(result, "Upgrade") == 0) {

    }
    else if(strcmp(result, "List") == 0) {

    }
    else if(strcmp(result, "View") == 0) {

    }
    else if(strcmp(result, "Exit") == 0) {

    }
}