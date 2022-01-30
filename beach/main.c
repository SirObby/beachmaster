#include <stdlib.h>
#include <argp.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>

#include "sys/install.h"

const char *argp_program_version =
    "argp-ex3 1.0";
const char *argp_program_bug_address =
    "<bug-gnu-utils@gnu.org>";

/* Program documentation. */
static char doc[] =
    "Argp example #3 -- a program with options and arguments using argp";

/* A description of the arguments we accept. */
static char args_doc[] = "COMMAND <PACKAGE>";

/* The options we understand. */
static struct argp_option options[] = {
    {"version", 'v', "VERSION", 0, "Set a specific version."},
    {"quiet", 'q', 0, 0, "Don't produce any output"},
    {"ask", 'a', 0, 0, "Ask to install packages"},
    {"search", 'c', 0, 0, "Search for packages"},
    {"build", 'b', 0, 0, "Build the package from scratch."},
    {"silent", 's', 0, OPTION_ALIAS},
    {0}};

/* Used by main to communicate with parse_opt. */
struct arguments
{
    char *args[99]; /* arg1 & arg2 */
    char *version;
    int silent, ask, search, build, argcount;
};

/* Parse a single option. */
static error_t
parse_opt(int key, char *arg, struct argp_state *state)
{
    /* Get the input argument from argp_parse, which we
       know is a pointer to our arguments structure. */
    struct arguments *arguments = state->input;

    switch (key)
    {
    case 'q':
    case 's':
        arguments->silent = 1;
        break;
    case 'v':
        arguments->version = arg;
        break;
    case 'a':
        arguments->ask = 1;
        break;
    case 'c':
        arguments->search = 1;
        break;
    case 'b':
        arguments->build = 1;
        break;

    case ARGP_KEY_ARG:
        if (state->arg_num >= 2)
            /* Too many arguments. */
            argp_usage(state);

        arguments->args[state->arg_num] = arg;
        arguments->argcount++;

        break;

    case ARGP_KEY_END:
        if (state->arg_num < 1)
            /* Not enough arguments. */
            argp_usage(state);
        break;

    default:
        return ARGP_ERR_UNKNOWN;
    }
    return 0;
}
/* Our argp parser. */
static struct argp argp = {options, parse_opt, args_doc, doc};

int main(int argc, char **argv)
{
    struct arguments arguments;

    /* Default values. */
    arguments.silent = 0;
    arguments.ask = 0;
    arguments.search = 0;
    arguments.build = 0;
    arguments.argcount = 0;


    /* Parse our arguments; every option seen by parse_opt will
       be reflected in arguments. */
    argp_parse(&argp, argc, argv,
               0,
               0, &arguments);

    // If the first argument is "install" then we should install the package
    if (strcmp(arguments.args[0], "install") == 0)
    {  
        install(arguments.argcount, arguments.args, arguments.silent, arguments.version);
    }

    // If the first argument is "init" then we should create the folder structure necessary for beach
    if (strcmp(arguments.args[0], "init") == 0)
    {
        // Make a folder in the directory /var/beach/pkg
        mkdir("/var/beach/", 0777);
        mkdir("/var/tmp/beach", 0777);
        mkdir("/etc/beach/", 0777);
        // Make a file in the directory /var/beach/ called installed
        FILE *fp = fopen("/var/beach/installed", "w+");
        fclose(fp);

        FILE *usersf = fopen("/etc/beach/users", "w+");
        fclose(usersf);
    }

    exit(0);
}
