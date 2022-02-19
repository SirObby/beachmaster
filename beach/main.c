#include "foo.h"
#include <argp.h>
#include <dialog.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arguments.h"

const char *argp_program_version = "argp-ex3 1.0";
const char *argp_program_bug_address = "<bug-gnu-utils@gnu.org>";

/* Program documentation. */
static char doc[] =
    "Argp example #3 -- a program with options and arguments using argp";

/* A description of the arguments we accept. */
static char args_doc[] = "[PACKAGES...]";

/* The options we understand. */
static struct argp_option options[] = {
    //{"verbose", 'v', 0, 0, "Produce verbose output"},
    {"quiet", 'q', 0, 0, "Don't ask any input"},
    {"silent", 's', 0, OPTION_ALIAS},
    {"no_output", 'n', 0, 0, "Don't produce any output."},
    {"output", 'o', "FILE", 0, "Output to FILE instead of standard output"},
    {0}};

/* Parse a single option. */
static error_t parse_opt(int key, char *arg, struct argp_state *state) {
  /* Get the input argument from argp_parse, which we
     know is a pointer to our arguments structure. */
  struct arguments *arguments = state->input;

  switch (key) {
  case 'q':
  case 's':
    arguments->silent = 1;
    break;
  case 'n':
    arguments->no_output = 1;
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
    arguments->argcount++;

    break;

  case ARGP_KEY_END:
    /*if (state->arg_num < 1)
      argp_usage(state);*/
    break;

  default:
    return ARGP_ERR_UNKNOWN;
  }
  return 0;
}
/* Our argp parser. */
static struct argp argp = {options, parse_opt, args_doc, doc};

WINDOW *create_newwin(int height, int width, int starty, int startx);
void destroy_win(WINDOW *local_win);

int main(int argc, char **argv) {

  struct arguments arguments;

  /* Default values. */
  arguments.silent = 0;
  arguments.verbose = 0;
  arguments.argcount = 0;
  arguments.no_output = 0;
  arguments.output_file = "-";

  /* Parse our arguments; every option seen by parse_opt will
     be reflected in arguments. */
  argp_parse(&argp, argc, argv, 0, 0, &arguments);

  d(arguments);

  exit(0);
}
