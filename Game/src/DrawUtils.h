#ifndef DRAWUTILS_H
#define DRAWUTILS_H
#include<GL/glew.h>

GLuint glTexImageTGAFile(const char* filename, int* outWidth, int* outHeight);
void glDrawSprite(GLuint tex, int x, int y, int w, int h, bool reverse=false);

#endif
