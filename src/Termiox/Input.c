#ifdef _WIN32

#include <Termiox/termiox.h>
#include <Windows.h>
#include <wincon.h>

static HANDLE hConsole = NULL;
static DWORD originalMode = 0;
static int isConsoleInitialized = 0;


static KeyCode convert_virtual_keycode(WORD virtual_keycode) {
    switch (virtual_keycode) {

        case VK_ESCAPE:
            return Key_Escape;

        case VK_BACK:
            return Key_Backspace;

        case VK_RETURN:
            return Key_Enter;

        case VK_UP:
            return Key_Up;

        case VK_DOWN:
            return Key_Down;

        case VK_LEFT:
            return Key_Left;

        case VK_RIGHT:
            return Key_Right;

        default:
            return Key_None;

    }
}

/*static KeyEventKind convert_keyboard_event(BOOL bKeyDown) {
    switch (bKeyDown) {

        case TRUE:
            return Press;

        case FALSE:
            return Release;

        default:
            return None;

    }
}*/

int initializeConsole() {

    hConsole = GetStdHandle(STD_INPUT_HANDLE);

    if (hConsole == NULL || hConsole == INVALID_HANDLE_VALUE) {
        fprintf(stderr, "Input GetStdHandle Failed!!");
        //GetLastError();
        return 0;
    }

    if (!GetConsoleMode(hConsole, &originalMode)) {
        fprintf(stderr, "GetConsoleMod Failed!!");
        // GetLastError();
        return 0;
    }

    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD outMode = 0;

    if (!GetConsoleMode(hOut, &outMode)) {
        fprintf(stderr, "Out GetStdHandle Failed!!");
       //GetLastError();
        return 0;
    }

    if (!SetConsoleMode(hOut, outMode | ENABLE_VIRTUAL_TERMINAL_PROCESSING)) {
        fprintf(stderr, "ANSI Escape Codes initialization Failed!!");
        //GetLastError();
        return 0;
    }

    isConsoleInitialized = 1;
    return 1;

}

void enableRawMode() {

    if (isConsoleInitialized == 0) {
        return;
    }


    DWORD rawMode = originalMode;

    rawMode &= ~(ENABLE_LINE_INPUT | ENABLE_ECHO_INPUT);

    if (!SetConsoleMode(hConsole, rawMode)) {
        fprintf(stderr, "enableRawMode Failed!!");
        GetLastError();
    }

}
void disableRawMode() {

    if (!isConsoleInitialized) {
        return;
    }

    if (!SetConsoleMode(hConsole, originalMode)) {
        fprintf(stderr, "disableRawMode Failed!!");
        GetLastError();
    }

}

int readKey(Key* key){

    if (key == NULL) {
        fprintf(stderr, "readKey: key is NULL");
        return 0;
    }

    key->code = Key_None;
    key->character = 0;
    key->modifier = Mod_None;

    static INPUT_RECORD record;
    static DWORD events_read;
    static int success = 0;

    while (1) {

        if (!ReadConsoleInputW(hConsole, &record, 1, &events_read)) {
            fprintf(stderr, "ReadConsoleInputW failed to read!!");
            GetLastError();
        }

        if (events_read == 0) {
            continue;
        }

        if (record.EventType != KEY_EVENT) {
            continue;
        }

        const KEY_EVENT_RECORD *keyboard_event = &record.Event.KeyEvent;

        if (!keyboard_event -> bKeyDown) {
            continue;
        }

        /*key->event = convert_keyboard_event(keyboard_event -> bKeyDown);*/

        key->code = convert_virtual_keycode(keyboard_event -> wVirtualKeyCode);

        key->character = (uint32_t)keyboard_event -> uChar.UnicodeChar;

        if (keyboard_event -> dwControlKeyState & SHIFT_PRESSED) {
            key->modifier |= Mod_Shift;
        }
        if (keyboard_event -> dwControlKeyState & (LEFT_CTRL_PRESSED | RIGHT_CTRL_PRESSED)) {
            key->modifier |= Mod_Ctrl;
        }
        if (keyboard_event -> dwControlKeyState & (LEFT_ALT_PRESSED | RIGHT_ALT_PRESSED)) {
            key->modifier |= Mod_Alt;
        }

        return 1;

    }
}

#endif




#ifndef _WIN32

#include <Termiox/termiox.h>
#include <locale.h>
#include <notcurses/notcurses.h>
#include <stdint.h>

static struct notcurses *ncContext = nullptr;
static notcurses_options ncOptions;
static int IsConsoleInitialized = 0;

static KeyCode convert_notCurses_keycode(const uint32_t notCurses_keycode) {
    switch (notCurses_keycode) {

        case NCKEY_ESC:
            return Key_Escape;

        case NCKEY_BACKSPACE:
            return Key_Backspace;

        case NCKEY_ENTER:
            return Key_Enter;

        case NCKEY_UP:
            return Key_Up;

        case NCKEY_DOWN:
            return Key_Down;

        case NCKEY_LEFT:
            return Key_Left;

        case NCKEY_RIGHT:
            return Key_Right;

        default:
            return Key_None;

    }
}

int initializeConsole() {

    if (setlocale(LC_ALL, "") == NULL) {
        fprintf(stderr, "Unable to set locale!");
        return 0;
    }

    IsConsoleInitialized = 1;
    return 1;

}

void enableRawMode() {

    if (!IsConsoleInitialized) {
        return;
    }

    ncContext = notcurses_init(&ncOptions, stdout);

    if (ncContext == nullptr) {
        fprintf(stderr, "NotCurses initialization failed!");
    }

}
void disableRawMode() {

    if (!IsConsoleInitialized) {
        return;
    }
    if (ncContext != nullptr) {
        notcurses_stop(ncContext);
    }
    ncContext = nullptr;

}
int readKey(Key *key) {

    static ncinput record;

    const uint32_t id = notcurses_get_blocking(ncContext, &record);

    key->code = convert_notCurses_keycode(id);

    if (id < NCKEY_INVALID) {
        key->character = id;
    }

    if (record.modifiers & NCKEY_MOD_SHIFT) {
        key->modifier |= Mod_Shift;
    }

    if (record.modifiers & NCKEY_MOD_CTRL) {
        key->modifier |= Mod_Ctrl;
    }
    if (record.modifiers & NCKEY_MOD_ALT) {
        key->modifier |= Mod_Alt;
    }

    return 1;
}
#endif

