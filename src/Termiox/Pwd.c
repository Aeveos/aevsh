#ifdef _WIN32

#include <Termiox/termiox.h>
#include <stdio.h>
#include <Windows.h>

int PrintWorkingDirectory(const char *color) {

    static char currentDir[MAX_PATH];
    DWORD length = GetCurrentDirectory(MAX_PATH, currentDir);

    if (length > 0) {
        printf("%s%s" RESET, color, currentDir);
        return 1;
    }
    else {
        fprintf(stderr, "GetCurrent Directory Failed!!");
        GetLastError();
        return 0;
    }
}

#endif

#ifndef _WIN32

#include <Termiox/termiox.h>
#include <stdio.h>
#include <unistd.h>

int PrintWorkingDirectory(const char *color) {

    static char currentDir[MAX_PATH];

    if (getcwd(currentDir, MAX_PATH) != NULL) {
        printf("%s%s>" RESET, color, currentDir);
        return 1;
    }
    else {
        perror("getcwd failed!!");
        return 0;
    }

}
#endif
