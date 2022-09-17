#ifndef _H_PROMPT
#define _H_PROMPT

#include <stdbool.h>

bool prompt(const char *message);
void enter(int x);
int options(char *message, char *options[2]);
char *get_input(const char *message);

#endif