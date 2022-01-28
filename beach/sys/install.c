#include "install.h"

#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <fcntl.h>
#include "../colors.h"

void install(int argc, char *args[99])
{
    printf("\n%s> %sbeach package manager\n\n", CYN, GRN);

    // Use fcntl to write and read lock /var/lock/beach.lock
    // This will prevent multiple instances of the program from running
    // at the same time.
    // Even when running multiple instances as root, this will prevent them from running at the same time.

    // Create a file /var/lock/beach.lock
    int lock = open("/var/lock/beach.lock", O_RDWR | O_CREAT, 0666);

    // Use fcntl to lock the file
    flock(lock, LOCK_EX);

    // Check if the file exists
    if (access("/var/lock/beach.lock", F_OK) != -1)
    {
        printf("%s> %sbeach is already running.\n", RED, GRN);
        printf("%s> %sPlease close the other instance of beach and try again.\n", RED, GRN);
        exit(1);
    }

    // Release the lock on the file /var/lock/beach.lock.
    flock(lock, LOCK_UN);

    // Close the file /var/lock/beach.lock
    close(lock);

    // Print a message that the program has done its job.
    printf("%s> %sbeach is now done.\n", GRN, CYN);
}