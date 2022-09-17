#include "prompt.h"
#include <stdio.h>

bool prompt(const char *message)
{
    printf("%s (y/n) ", message);
    // Get input from the user
    char input;
    scanf("%s", &input);
    printf("%c", input);
    // Check if the user wants to continue
    if (input == 'y' || input == 'Y')
    {
        printf("es\n");
        return true;
    }
    if (input == 'n' || input == 'N')
    {
        printf("o\n");
        return false;
    }
    if (input == '\n')
        return false;
    return prompt(message);
};

void enter(int x)
{
    if (x == 0)
    {
        printf("Press 'ENTER' to continue");
    }
    char input;
    scanf("%c", &input);
    if (input == '\n' && x == 0)
        return;
    enter(x - 1);
};

int options(char *message, char *options[])
{
    printf("%s\n", message);
    for (size_t i = 0; i < 2; i++)
    {
        printf("%d %s\n", i, options[i]);
    }
    printf("Chose an option [0 - %d]: ", 1);
    int input;
    scanf("%d", &input);
    if (input < 0 || input > 1)
    {
        printf("Invalid option.\n");
        // return options(message, options, c);
    }
    return input;
}
char *get_input(const char *message)
{
    
    return "";
    //return alline;
    // system(in);
    //return in;
};