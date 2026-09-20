#pragma once


/*Input.h*/

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
typedef enum {

    // Regular
    BLACK,
    RED,
    GREEN,
    YELLOW,
    BLUE,
    PURPLE,
    CYAN,
    WHITE,

    // Bold
    BOLD_BLACK,
    BOLD_RED,
    BOLD_GREEN,
    BOLD_YELLOW,
    BOLD_BLUE,
    BOLD_PURPLE,
    BOLD_CYAN,
    BOLD_WHITE,

    COLOR_NONE,

}Color;

typedef enum {

    // Underline
    UNDERLINE_BLACK,
    UNDERLINE_RED,
    UNDERLINE_GREEN,
    UNDERLINE_YELLOW,
    UNDERLINE_BLUE,
    UNDERLINE_PURPLE,
    UNDERLINE_CYAN,
    UNDERLINE_WHITE,

    // Darkened (dim)
    DIM_BLACK,
    DIM_RED,
    DIM_GREEN,
    DIM_YELLOW,
    DIM_BLUE,
    DIM_PURPLE,
    DIM_CYAN,
    DIM_WHITE,

    // Highlighters
    HL_YELLOW,
    HL_GREEN,
    HL_CYAN,
    HL_BLUE,
    HL_RED,
    HL_PURPLE,

    // Background
    BG_BLACK,
    BG_RED,
    BG_GREEN,
    BG_YELLOW,
    BG_BLUE,
    BG_PURPLE,
    BG_CYAN,
    BG_WHITE,

    // High intensity background
    BG_HI_BLACK,
    BG_HI_RED,
    BG_HI_GREEN,
    BG_HI_YELLOW,
    BG_HI_BLUE,
    BG_HI_PURPLE,
    BG_HI_CYAN,
    BG_HI_WHITE,

    // Darkened high intensity
    DIM_HI_BLACK,
    DIM_HI_RED,
    DIM_HI_GREEN,
    DIM_HI_YELLOW,
    DIM_HI_BLUE,
    DIM_HI_PURPLE,
    DIM_HI_CYAN,
    DIM_HI_WHITE,

    // High intensity
    HI_BLACK,
    HI_RED,
    HI_GREEN,
    HI_YELLOW,
    HI_BLUE,
    HI_PURPLE,
    HI_CYAN,
    HI_WHITE,

    // Bold high intensity
    B_HI_BLACK,
    B_HI_RED,
    B_HI_GREEN,
    B_HI_YELLOW,
    B_HI_BLUE,
    B_HI_PURPLE,
    B_HI_CYAN,
    B_HI_WHITE,

}ColorStyle;

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
extern int PrintWorkingDirectory(Color color);

/*Colors.h*/

// Regular text
#define aBLACK   "\033[0;30m"
#define aRED     "\033[0;31m"
#define aGREEN   "\033[0;32m"
#define aYELLOW  "\033[0;33m"
#define aBLUE    "\033[0;34m"
#define aPURPLE  "\033[0;35m"
#define aCYAN    "\033[0;36m"
#define aWHITE   "\033[0;37m"

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
#define BLACKHB  "\033[0;100m"
#define REDHB    "\033[0;101m"
#define GREENHB  "\033[0;102m"
#define YELLOWHB "\033[0;103m"
#define BLUEHB   "\033[0;104m"
#define PURPLEHB "\033[0;105m"
#define CYANHB   "\033[0;106m"
#define WHITEHB  "\033[0;107m"

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