#pragma once
#include"Animation.h"
class Sprite {
protected:
	AnimationData * curDef;
	int position[2];
	int size[2];
	bool reverse;
public:
	virtual int update(int deltatime) = 0;
	int onscreen(int x, int y);
	int getX();
	int getY();
	int getXSize();
	int getYSize();
	bool getReverse();
	void AnimationUpdate(int deltatime);
	GLuint getImage();
};
