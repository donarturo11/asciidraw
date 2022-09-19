#ifndef _CONIO_H_
#define _CONIO_H_
#if defined(_WIN32) || defined(_WIN64)
#include "conio2-win.h"
#else
#include "conio2-ansi.h"
#endif
#endif //_CONIO_H_