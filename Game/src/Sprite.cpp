#include"Sprite.h"

int Sprite::onscreen(int x, int y) {
	int sprX = position[0];
	int sprY = position[1];
	if (sprX + size[0] < x) return 0;
	if (sprY + size[1] < y) return 0;
	if (sprX > x + 800) return 0;
	if (sprY > y + 600) return 0;
	return 1;
}

int Sprite::getX() {
	return position[0];
}

int Sprite::getY() {
	return position[1];
}

int Sprite::getXSize() {
	return size[0];
}

int Sprite::getYSize() {
	return size[1];
}

GLuint Sprite::getImage() {
	return curDef->getImage();
}

bool Sprite::getReverse() {
	return reverse;
}

void Sprite::AnimationUpdate(int deltatime) {
	curDef->AnimUpdate(deltatime);
}