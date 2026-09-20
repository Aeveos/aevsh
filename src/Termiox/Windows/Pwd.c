#ifdef _WIN32

#include <Termiox/termiox.h>
#include <stdio.h>
#include <Windows.h>

int PrintWorkingDirectory(Color color) {

    static char currentDir[MAX_PATH];
    DWORD length = GetCurrentDirectory(MAX_PATH, currentDir);
    static const char *printColor = "";

    if (length > 0) {

        switch (color) {
            case BLACK:
                printColor = aBLACK;
                break;
            case RED:
                printColor = aRED;
                break;
            case GREEN:
                printColor = aGREEN;
                break;
            case YELLOW:
                printColor = aYELLOW;
                break;
            case BLUE:
                printColor = aBLUE;
                break;
            case PURPLE:
                printColor = aPURPLE;
                break;
            case CYAN:
                printColor = aCYAN;
                break;
            case WHITE:
                printColor = aWHITE;
                break;
            case BOLD_BLACK:
                printColor = BBLACK;
                break;
            case BOLD_RED:
                printColor = BRED;
                break;
            case BOLD_GREEN:
                printColor = BGREEN;
                break;
            case BOLD_YELLOW:
                printColor = BYELLOW;
                break;
            case BOLD_BLUE:
                printColor = BBLUE;
                break;
            case BOLD_PURPLE:
                printColor = BPURPLE;
                break;
            case BOLD_CYAN:
                printColor = BCYAN;
                break;
            case BOLD_WHITE:
                printColor = BWHITE;
                break;
            case COLOR_NONE:
                printColor = "";
                break;
            default: printColor = "";
        }
        printf("%s%s" RESET, printColor, currentDir);

        return 1;
    }
    else {
        fprintf(stderr, "GetCurrent Directory Failed!!");
        GetLastError();
        return 0;
    }
}

#endif
