#ifndef _H_PARSER_
#define _H_PARSER_

// Make a function that will parse a file in the argument and take in arguments like the silent flag
// This function will return 1 if the file was successfully parsed, and 0 if it was not
// This function will also print out the file name and version if it was successfully parsed
int parse_file(char *file, int silent);

#endif