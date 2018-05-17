#include"Background.h"

int getTile(BackgroundDef *bd, int x, int y) {
	return bd->tiles[x / bd->width][y / bd->height];
}

void BackgroundLoad(BackgroundDef *bg) {
	GLuint brick = glTexImageTGAFile("assets/background/floor/brick.tga", &bg->width, &bg->height);
	GLuint blue_sky = glTexImageTGAFile("assets/background/sky/blue.tga", &bg->width, &bg->height);

	int i, j;
	for (i = 0; i < 36; i++) {
		for (j = 0; j < 20; j++) {
			if (j < 15) bg->tiles[i][j] = blue_sky;
			else bg->tiles[i][j] = brick;
		}
	}
}


/*
Background::Background() {

int concrete = glTexImageTGAFile("assets/background/conc.tga", &bg->width, &bg->height);
int tile = glTexImageTGAFile("assets/background/tile.tga", &bg->width, &bg->height);
int metal = glTexImageTGAFile("assets/background/bg.tga", &bg->width, &bg->height);
int blue = glTexImageTGAFile("assets/background/blue.tga", &bg->width, &bg->height);

int i, j;
for (i = 0; i < 16; i++) {
for (j = 0; j < 16; j++) {
if (j < 5) bg->tiles[j][i] = blue;
else if (j < 10) bg->tiles[j][i] = tile;
else if (i == 15) bg->tiles[j][i] = metal;
else bg->tiles[j][i] = concrete;
}
}
}

int Background::getTile(int x, int y) {
return tiles[x / width][y / height];
}

int Background::getHeight() {
return height;
}

int Background::getWidth() {
return width;
}
*/