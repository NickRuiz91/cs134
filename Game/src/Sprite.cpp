#include"Sprite.h"

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