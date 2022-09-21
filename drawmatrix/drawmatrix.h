#ifndef DRAWMATRIX_H
#define DRAWMATRIX_H
typedef struct drawmatrix drawmatrix;
drawmatrix *drawmatrix_init(int width, int height);
void drawmatrix_initPicture(drawmatrix *d);
void drawmatrix_destroy(drawmatrix *d);
void drawmatrix_setDimensions(drawmatrix *d, int width, int height);
void drawmatrix_setMaxPositions(drawmatrix *d);
void drawmatrix_resize(drawmatrix *d, int width, int height);
char drawmatrix_getChar(drawmatrix *d, int x, int y);
void drawmatrix_put(drawmatrix *d, int x, int y, char c);
void drawmatrix_draw(drawmatrix *d);
void drawmatrix_initPicture(drawmatrix *d);
void drawmatrix_clearPicture(drawmatrix *d);
char *drawmatrix_getPicture(drawmatrix *d);
int drawmatrix_calculatePosition(drawmatrix *d, int x, int y);
#endif
