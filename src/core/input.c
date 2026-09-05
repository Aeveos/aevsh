#include <platform/platform.h>
#include <core/input.h>

// #define DEBUG

char unbuffered_input[256];

static int input_index = 0;

int input() {
    Key key;

    if (!initializeConsole()) {
        return 0;
    }

    input_index = 0;
    unbuffered_input[0] = '\0';

    enableRawMode();

    while (1) {

        if (!readKey(&key)) {
            printf("Unable to call readKey!");
            break;
        }

        switch (key.code) {
           case Key_Enter:
                printf("\r\n");
                unbuffered_input[input_index] = '\n';
                disableRawMode();
#ifdef DEBUG
                printf("%s\n", unbuffered_input);
#endif

                return 1;

           case Key_Backspace:
               if (input_index > 0) {
                   input_index--;
                   unbuffered_input[input_index] = '\0';
                   printf("\x08 \x08");
                   fflush(stdout);
               }
               break;

           case Key_None:

               if (key.character != '\0' &&
                   key.character != '\n' &&
                   key.character != '\r' &&
                   input_index < sizeof(unbuffered_input) - 1) {


                   unbuffered_input[input_index] = (char)key.character;

                   input_index++;

                   unbuffered_input[input_index] = '\0';

                   //printf("%c", (char)key.character);

                   putchar((char)key.character);
                   fflush(stdout);

                   }
                break;

           default: break;
       }

    }

    disableRawMode();

    return 0;
}
