#include "foo.h"

#include <dialog.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/fcntl.h>

#include "work.h"
#include "arguments.h"
#include "colors.h"

#define LEN(arr) ((int)(sizeof(arr) / sizeof(arr)[0]))

void bar()
{
    printf("foobar\n");
}

void d(struct arguments ar)
{
    // extern struct arguments arguments;

    if (!ar.silent)
    {
        char *modes[] =
            {
                "Install", "Install packages.",
                "Remove", "Remove packages.",
                "Upgrade", "Upgrade packages.",
                "List", "List installed packages.",
                //"View", "View the contents of a package.",
                "Exit", "Exit beach"};

        dialog_vars.keep_tite = true;
        dialog_vars.backtitle = "beach";
        dialog_vars.title = "beach";

        init_dialog(stdin, stdout);
        dialog_menu("beach package manager (beach version 0.0.1)", "Choose an option.", 17, 75, 7, LEN(modes) / 2, modes);
        end_dialog();
        char *result = dialog_vars.input_result;
        // printf("%s\n", result);

        // printf("\033[2J\033[H");

        if (strcmp(result, "Install") == 0)
        {
            // Instalin

            dialog_vars.input_result = NULL;

            char *modes[] =
                {
                    "Internet", "Download package script from the internet.",
                    "Local", "Install package script from a local file.",
                    //"Upgrade", "Upgrade packages.",
                    //"List", "List installed packages.",
                    //"View", "View the contents of a package.",
                    /*"Exit", "Exit beach"*/};

            init_dialog(stdin, stdout);
            dialog_menu("beach package manager (beach version 0.0.1)", "How do you want to install?", 17, 75, 7, LEN(modes) / 2, modes);
            end_dialog();
            char *result_i = dialog_vars.input_result;
            // printf("%s\n", result_i);

            // printf("\033[2J\033[H");

            if (strcmp(result_i, "Internet") == 0)
            {
                printf("Not implemented yet.\n");
            }
            else if (strcmp(result_i, "Local") == 0)
            {
                dialog_vars.input_result = NULL;

                // printf("Finding local...\n");

                init_dialog(stdin, stdout);
                dialog_inputbox("beach package manager (beach version 0.0.1)", "Enter a path to the package.", 17, 75, "", 0);
                end_dialog();

                printf("%s\n", dialog_vars.input_result);

                char buffer[100];
                char full_script[4096];

                FILE *fp = fopen(dialog_vars.input_result, "r"); // do not use "rb"
                while (fgets(buffer, sizeof(buffer), fp))
                {
                    //printf("-- %s", buffer);
                    strcat(full_script, buffer);
                }
                fclose(fp);
                printf("%s", full_script);
            }
        }
    }
    else
    {

        printf("%d\n", ar.argcount);
        if (ar.argcount <= 0)
            printf("%s* %sQuiet beach installs, must require an argument.\n", RED, CYN);
    }

    // printf("\033[2J");
}

/*
init_dialog(stdin, stdout);
            dialog_vars.backtitle = "beach";
            dialog_inputbox("beach package manager (beach version 0.0.1)", "Package name, or URL", 17, 75, "", 0);
            end_dialog();

            printf("%s\n", dialog_vars.input_result);
*/
