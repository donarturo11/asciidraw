#ifndef _LINUXCONIO_H
#define _LINUXCONIO_H

#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

#define cprintf printf
#define cscanf scanf
#define cgets gets

#define CLEAR "\x1b[2J"
#define SET11 "\x1b[1;1f"
#define CURSOR_UP "\x1b[1A"
#define ERASE_LINE "\x1b[2K"
#define BLINK_SLOW "\x1b[5m"
#define BLINK_RAPID "\x1b[6m"
#define CC_CLEAR "\x1b[0m"

enum COLORS
{
  BLACK = 0,
  BLUE = 1,
  GREEN = 2,
  CYAN = 3,
  RED = 4,
  MAGENTA = 5,
  BROWN = 6,
  LIGHTGRAY = 7,
  DARKGRAY = 8,
  LIGHTBLUE = 9,
  LIGHTGREEN = 10,
  LIGHTCYAN = 11,
  LIGHTRED = 12,
  LIGHTMAGENTA = 13,
  YELLOW = 14,
  WHITE = 15,
  BLINK = 128
};

#ifdef __cplusplus
extern "C" {
#endif

static struct termios oldterm, newterm;
void initTermios(int echo);
void resetTermios();
int getch_(int echo);
void cagxy(unsigned int x, unsigned int y);
void clrscr();
int getch();
int getche();
void gotox(unsigned int x);
void gotoxy(unsigned int x, unsigned int y);
void nocursor();
void normvideo();
void showcursor();
void textcolor(int newcolor);
void textbackground(int newcolor);
void delline();
void clreol();
int putch(const char c);
int cputs(const char*str);
int wherexy(int *x, int *y);
int wherex();
int wherey();
int kbhit();

#ifdef __cplusplus
}
#endif

#endif // _LINUXCONIO_H

