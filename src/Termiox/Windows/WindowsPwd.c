#ifdef _WIN32

#include <Termiox/PrintWorkingDirectory.h>
#include <stdio.h>
#include <Windows.h>

int PrintWorkingDirectory() {

    static char currentDir[MAX_PATH];
    DWORD length = GetCurrentDirectory(MAX_PATH, currentDir);

    if (length > 0) {
        printf("%s> ", currentDir);
        return 1;
    }
    else {
        fprintf(stderr, "GetCurrent Directory Failed!!");
        GetLastError();
        return 0;
    }
}

#endif
