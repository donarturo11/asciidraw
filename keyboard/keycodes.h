#ifndef _KEYSEQUENCES_H
#define _KEYSEQUENCES_H

#define ESC 27

#ifdef _WIN32
#define SEQ_CODE 224
#define K_UP SEQ_CODE+72
#define K_DOWN SEQ_CODE+80
#define K_RIGHT SEQ_CODE+77
#define K_LEFT SEQ_CODE+75
#else
#define SEQ_CODE ESC+91
#define K_UP SEQ_CODE+65
#define K_DOWN SEQ_CODE+66
#define K_RIGHT SEQ_CODE+67
#define K_LEFT SEQ_CODE+68
#endif

#endif
