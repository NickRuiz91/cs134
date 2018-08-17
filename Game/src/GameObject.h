#pragma once
#include"Vector2.h"

class GameObject {
public:
	Vector2 position;
	static bool onscreen(int sprx, int spry, int width, int height, int scale, int camx, int camy);
	//virtual void update(int xpos, int ypos) {}
	virtual void render(int camx, int camy) = 0;
	virtual int getX() { return (int)position.x; }
	virtual int getY() { return (int)position.y; }
};
