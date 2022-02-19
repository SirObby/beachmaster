#include <stdio.h>
#include "colors.h"

#include "work.h"

void work_configure(char *f) {
    printf("\r%s* Configuring %s\n", CYN, f);
};
void work_install(char *f) {
    printf("%s* Installing %s\n", CYN, f);
};
void work_post_install(char *f) {
    printf("%s* Post-installing %s\n", CYN, f);
};
void work_uninstall(char *f) {
    printf("%s* Uninstalling %s\n", CYN, f);
};