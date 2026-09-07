#ifndef _WIN32

#include <Termiox/PrintWorkingDirectory.h>
#include <stdio.h>
#include <unistd.h>

#define MAX_PATH 260

int PrintWorkingDirectory() {

    static char currentDir[MAX_PATH];

    if (getcwd(currentDir, MAX_PATH) != NULL) {
        printf("%s> ", currentDir);
        return 1;
    }
    else {
        perror("getcwd Failed!!");
        return 0;
    }
}

#endif
