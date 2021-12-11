#include <stdlib.h>
#include <argp.h>

const char *argp_program_version =
    "beach pre-0.0.1";
const char *argp_program_bug_address =
    "<https://github.com/SirObby/beachmaster/issues>";

/* Program documentation. */
static char doc[] =
    "Beach - Package Manager for Beachmaster";

/* A description of the arguments we accept. */
static char args_doc[] = "[COMMAND] PACKAGE...";

/* The options we understand. */
static struct argp_option options[] = {
    //    {"verbose", 'v', 0, 0, "Produce verbose output"},
    {"search", 'd', 0, OPTION_DOC, "What package to search.", 0},
    {"quiet", 'q', 0, 0, "Don't produce any output", 1},
    {"silent", 's', 0, OPTION_ALIAS, 1},
    {"deps", 'd', "DEPS", 0, "What dependencies to use. Separate with comma.", 1},
    {0}};

/* Used by main to communicate with parse_opt. */
struct arguments
{
    char *args[2]; /* arg1 & arg2 */
    int silent, verbose;
    char *output_file;
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
        arguments->verbose = 1;
        break;
    case 'o':
        arguments->output_file = arg;
        break;

    case ARGP_KEY_ARG:
        //if (state->arg_num >= 2)
            /* Too many arguments. */
            //argp_usage(state);

        arguments->args[state->arg_num] = arg;

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
    arguments.verbose = 0;
    arguments.output_file = "-";

    /* Parse our arguments; every option seen by parse_opt will
     be reflected in arguments. */
    argp_parse(&argp, argc, argv,
               0,
               0, &arguments);

    exit(0);
}