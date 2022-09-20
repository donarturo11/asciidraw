#include "keyboard.h"

struct keyboard
{
	int active;
};

keyboard *keyboardInit()
{
	keyboard* k = NULL;
	k = (keyboard*) malloc(sizeof(keyboard));
	return k;
}

void keyboardDelete(keyboard *k)
{
	free(k);
}

void keyboardLoop(keyboard *k)
{
    k->active = TRUE;

    while (k->active){
		keyboardDetect(k); 
    }
}

void keyboardDetect(keyboard *k)
{
	int keyCode=getch();
	while (kbhit()){
		keyCode+=getch();
	}
	keyboardShortcut(k, keyCode);
}

int keyboardShortcut(keyboard *k, int keyCode)
{
    switch (keyCode) {
        case 'q': k->active = FALSE; break;
		case K_UP: printf("UP\n"); break;
		default: printf("KeyCode is %i\n", keyCode); break;
    }
	return keyCode;
}

void keyboardTest()
{
    keyboard *kbd=keyboardInit();
    keyboardLoop(kbd);
    keyboardDelete(kbd);
}
