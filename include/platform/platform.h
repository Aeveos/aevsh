#pragma once

#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

typedef enum {

    Key_None,
    Key_Escape,
    Key_Backspace,
    Key_Enter,
    Key_Up,
    Key_Down,
    Key_Left,
    Key_Right,

}KeyCode;

typedef enum {

    Mod_None = 0,
    Mod_Shift = 1 << 0,
    Mod_Ctrl = 1 << 1,
    Mod_Alt = 1 << 2,

}KeyModifier;

/*typedef enum {

    None,
    Press,
    Release,

} KeyEventKind;*/

typedef struct{

    KeyCode code;
    uint32_t character;
    uint32_t modifier;
    bool event;

} Key;

extern int initializeConsole();
extern void disableRawMode();
extern void enableRawMode();
extern int readKey(Key *key);