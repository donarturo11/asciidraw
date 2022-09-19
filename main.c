#include <stdio.h>
#include "conio2.h"
#include "globals.h"
#include "keyboard/keyboard.h"

void greeting()
{
    printf("Welcome to ASCII Draw\n"
           "To quit press q.\n");
}

int main()
{
    gotoxy(0, 0);
    clrscr();
    greeting();
    keyboardTest();
 	return 0;
}
