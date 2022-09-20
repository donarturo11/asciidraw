#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <stdio.h>
#include <stdlib.h>
#include "conio2.h"
#include "keycodes.h"
#include "globals.h"

typedef struct keyboard keyboard;
keyboard *keyboardInit();
void keyboardDelete(keyboard *k);
void keyboardLoop(keyboard *k);
void keyboardDetect(keyboard *k);
int keyboardShortcut(keyboard *k, int keyCode);
void keyboardTest();

#endif
