#pragma once


/*Input.h*/

#include <stdio.h>
#include <stdint.h>
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

/*PrintWorkingDirectory.h*/

#define MAX_PATH 260
extern int PrintWorkingDirectory(const char *color);

/*Colors.h*/

// Regular text
#define BLACK   "\033[0;30m"
#define RED     "\033[0;31m"
#define GREEN   "\033[0;32m"
#define YELLOW  "\033[0;33m"
#define BLUE    "\033[0;34m"
#define PURPLE  "\033[0;35m"
#define CYAN    "\033[0;36m"
#define WHITE   "\033[0;37m"

// Bold text
#define BBLACK   "\033[1;30m"
#define BRED     "\033[1;31m"
#define BGREEN   "\033[1;32m"
#define BYELLOW  "\033[1;33m"
#define BBLUE    "\033[1;34m"
#define BPURPLE  "\033[1;35m"
#define BCYAN    "\033[1;36m"
#define BWHITE   "\033[1;37m"

// Underline text
#define UBLACK   "\033[4;30m"
#define URED     "\033[4;31m"
#define UGREEN   "\033[4;32m"
#define UYELLOW  "\033[4;33m"
#define UBLUE    "\033[4;34m"
#define UPURPLE  "\033[4;35m"
#define UCYAN    "\033[4;36m"
#define UWHITE   "\033[4;37m"

// Darkened (dim) text
#define DBLACK   "\033[2;30m"
#define DRED     "\033[2;31m"
#define DGREEN   "\033[2;32m"
#define DYELLOW  "\033[2;33m"
#define DBLUE    "\033[2;34m"
#define DPURPLE  "\033[2;35m"
#define DCYAN    "\033[2;36m"
#define DWHITE   "\033[2;37m"

// Highlighters
#define HLYELLOW  "\033[0;30;103m"  // black text on bright yellow
#define HLGREEN   "\033[0;30;102m"  // black text on bright green
#define HLCYAN    "\033[0;30;106m"  // black text on bright cyan
#define HLBLUE    "\033[0;30;104m"  // white text on bright blue
#define HLRED     "\033[0;30;101m"  // white text on bright red
#define HLPURPLE  "\033[0;30;105m"  // white text on bright purple

// Background
#define BLACKB   "\033[40m"
#define REDB     "\033[41m"
#define GREENB   "\033[42m"
#define YELLOWB  "\033[43m"
#define BLUEB    "\033[44m"
#define PURPLEB  "\033[45m"
#define CYANB    "\033[46m"
#define WHITEB   "\033[47m"

// High intensity background
#define BLACKHBG  "\033[0;100m"
#define REDHBG    "\033[0;101m"
#define GREENHBG  "\033[0;102m"
#define YELLOWHBG "\033[0;103m"
#define BLUEHBG   "\033[0;104m"
#define PURPLEHBG "\033[0;105m"
#define CYANHBG   "\033[0;106m"
#define WHITEHBG  "\033[0;107m"

// Darkened high-intensity text
#define DHBLACK   "\033[2;90m"
#define DHRED     "\033[2;91m"
#define DHGREEN   "\033[2;92m"
#define DHYELLOW  "\033[2;93m"
#define DHBLUE    "\033[2;94m"
#define DHPURPLE  "\033[2;95m"
#define DHCYAN    "\033[2;96m"
#define DHWHITE   "\033[2;97m"

// High intensity text
#define HBLACK   "\033[0;90m"
#define HRED     "\033[0;91m"
#define HGREEN   "\033[0;92m"
#define HYELLOW  "\033[0;93m"
#define HBLUE    "\033[0;94m"
#define HPURPLE  "\033[0;95m"
#define HCYAN    "\033[0;96m"
#define HWHITE   "\033[0;97m"

// Bold high intensity text
#define BHBLACK   "\033[1;90m"
#define BHRED     "\033[1;91m"
#define BHGREEN   "\033[1;92m"
#define BHYELLOW  "\033[1;93m"
#define BHBLUE    "\033[1;94m"
#define BHPURPLE  "\033[1;95m"
#define BHCYAN    "\033[1;96m"
#define BHWHITE   "\033[1;97m"

// Reset
#define RESET "\033[0m"

/*ClrScreen.h*/

int ClrScreen();

