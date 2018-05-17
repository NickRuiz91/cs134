#pragma once
#pragma once
#include"DrawUtils.h"

/*
class Background {
private:
int width;
int height;
int tiles[16][16];
public:
Background();
int getTile(int x, int y);
int getWidth();
int getHeight();
};
*/

typedef struct {
	int width;
	int height;
	GLuint tiles[36][20];
} BackgroundDef;

int getTile(BackgroundDef *bd, int x, int y);
void BackgroundLoad(BackgroundDef* bg);
