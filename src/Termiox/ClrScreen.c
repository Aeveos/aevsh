#ifdef _WIN32

#include <Termiox/termiox.h>
#include <stdio.h>
#include <Windows.h>

int ClrScreen() {

    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    COORD cordScreen = {0, 0};
    DWORD charsWritten;

    if (!GetConsoleScreenBufferInfo(hOut, &csbi)) {
        GetLastError();
        return 0;
    }

    DWORD conSize = csbi.dwSize.X * csbi.dwSize.Y;

    FillConsoleOutputCharacter(hOut, ' ', conSize, cordScreen, &charsWritten);

    if (!FillConsoleOutputAttribute(hOut, csbi.wAttributes, conSize, cordScreen, &charsWritten)) {
        fprintf(stderr, "FillConsoleOutputAttribute failed!!");
        GetLastError();
        return 0;
    }

    if (!SetConsoleCursorPosition(hOut, cordScreen)) {
        fprintf(stderr, "SetConsoleCursorPosition failed!!");
        GetLastError();
        return 0;
    }

}

#endif

#ifndef _WIN32

#include <Termiox/termiox.h>
#include <stdio.h>
#include <unistd.h>

int ClrScreen() {

    const char *clrSeq = "\033[2J\033[H";
    write(STDOUT_FILENO, clrSeq, 8);

}

#endif
