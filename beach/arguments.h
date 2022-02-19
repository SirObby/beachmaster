#ifndef _H_BEACH_ARGUMENTS_H_
#define _H_BEACH_ARGUMENTS_H_

/* Used by main to communicate with parse_opt. */
struct arguments {
  int silent, verbose, argcount, no_output;
  char *args[99]; /* arg1 & arg2 */
  char *output_file;
};

#endif