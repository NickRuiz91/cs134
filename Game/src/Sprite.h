#pragma once
#include"Animation.h"
class Sprite {
protected:
	AnimationData * curDef;
	int size[2];
	bool reverse;
public:
	int getXSize();
	int getYSize();
	bool getReverse();
	void AnimationUpdate(int deltatime);
	GLuint getImage();
};
