#include"Camera.h"

void CameraUpdate(Camera *c, char a, char s, char d, char w, int deltatime, int space, int playerX, int playerY) {
	if (space) {
		c->x = playerX - 400;
		c->y = playerY - 300;
	}
	else if (d && w) {
		c->x += deltatime / 2;
		c->y -= deltatime / 2;
	}
	else if (d && s) {
		c->x += deltatime / 2;
		c->y += deltatime / 2;
	}
	else if (a && w) {
		c->x -= deltatime / 2;
		c->y -= deltatime / 2;
	}
	else if (a && s) {
		c->x -= deltatime / 2;
		c->y += deltatime / 2;
	}
	else if (a) {
		c->x -= deltatime / 2;
	}
	else if (d) {
		c->x += deltatime / 2;
	}
	else if (w) {
		c->y -= deltatime / 2;
	}
	else if (s) {
		c->y += deltatime / 2;
	}

	if (c->x < 0) c->x = 0;
	if (c->x > 2400) c->x = 2400;
	if (c->y < 0) c->y = 0;
	if (c->y > 2600) c->y = 2600;
}