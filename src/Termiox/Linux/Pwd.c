#ifndef _WIN32

#include <Termiox/termiox.h>
#include <stdio.h>
#include <unistd.h>

#define MAX_PATH 260

int PrintWorkingDirectory(const char *color) {

    static char currentDir[MAX_PATH];

    if (getcwd(currentDir, MAX_PATH) != NULL) {
        printf("%s%s>" RESET, color, currentDir);
    }


        return 1;

    }
    else {
        perror("getcwd Failed!!");
        return 0;
    }
}

#endif
