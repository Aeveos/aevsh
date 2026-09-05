#ifdef _WIN32

#include <platform/platform.h>
#include <Windows.h>
#include <wincon.h>

HANDLE hConsole = NULL;
DWORD originalMode = 0;
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
        printf("GetStdHandle Failed");
        GetLastError();
        return 0;
    }

    if (!GetConsoleMode(hConsole, &originalMode)) {
        printf("GetConsoleMode Failed");
        GetLastError();
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
        printf("EnableRawMode Failed");
        GetLastError();
    }

}
void disableRawMode() {

    if (!isConsoleInitialized) {
        return;
    }

    if (!SetConsoleMode(hConsole, originalMode)) {
        printf("DisableRawMode Failed");
        GetLastError();
    }

}

int readKey(Key* key){

    if (key == NULL) {
        printf("readKey: Key is NULL");
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
            printf("ReadConsoleInput Failed");
            GetLastError();
        }

        if (events_read == 0) {
            continue;
        }

        if (record.EventType != KEY_EVENT) {
            continue;
        }

        KEY_EVENT_RECORD *keyboard_event = &record.Event.KeyEvent;

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
