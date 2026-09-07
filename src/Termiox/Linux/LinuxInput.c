#ifndef _WIN32

#include <Termiox/Input.h>
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
