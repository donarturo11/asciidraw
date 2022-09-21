#include "drawmatrix.h"
#include <stdio.h>
#include <stdlib.h>

struct drawmatrix {
    int xMax, yMax;
    int width, height;
    int focus;
    char* picture;
};

drawmatrix *drawmatrix_init(int width, int height)
{
    drawmatrix *d = (drawmatrix*) malloc(sizeof(drawmatrix));
    drawmatrix_setDimensions(d, width, height);	
    drawmatrix_initPicture(d);
    return d;
} 

void drawmatrix_destroy(drawmatrix *d)
{
    free(d);
}

void drawmatrix_setDimensions(drawmatrix *d, int width, int height)
{
    d->width = width;
    d->height = height;
    drawmatrix_setMaxPositions(d);
}

void drawmatrix_setMaxPositions(drawmatrix *d)
{
    d->xMax = (d->width)-1;
    d->yMax = (d->height)-1;
}

void drawmatrix_resize(drawmatrix *d, int width, int height)
{
    drawmatrix_setDimensions(d, width, height);
    d->picture=realloc(d->picture, sizeof(char)*(width+1)*height);
    drawmatrix_clearPicture(d);
}

void drawmatrix_put(drawmatrix *d, int x, int y, char c)
{
    int position=drawmatrix_calculatePosition(d, x, y);
    if (x<=d->xMax && y<=d->yMax)
        d->picture[position]=c;
}

char drawmatrix_getChar(drawmatrix *d, int x, int y)
{
    int width = d->width;
	
	return d->picture[y*width + x];
}

void drawmatrix_draw(drawmatrix *d)
{
    printf("\n%s\n", d->picture);
}

void drawmatrix_initPicture(drawmatrix *d)
{
    int height = d->height;
	int width = d->width;	
	d->picture=calloc(height * (width+1), sizeof(char));
	drawmatrix_clearPicture(d);
}

void drawmatrix_clearPicture(drawmatrix *d)
{
    int height = d->height;
	int width = d->width;
	char c;
#ifdef _MATRIX_DEBUG
	c = '0';
#else
	c = ' ';
#endif
	int position = 0;
    for (int i=0; i<(width*height+height); i++) d->picture[i]=c;	
    for (int y=0; y<height; y++) {
		position = drawmatrix_calculatePosition(d, width, y);
		d->picture[position]='\n';
	}
}

char *drawmatrix_getPicture(drawmatrix *d)
{
    return d->picture;
}

int drawmatrix_calculatePosition(drawmatrix *d, int x, int y)
{
   return (d->width*y + (x+y));
}

