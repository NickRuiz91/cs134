#include"Camera.h"

Camera::Camera() {
	x = 0;
	y = 2000;
}

int Camera::getX() {
	return x;
}

int Camera::getY() {
	return y;
}

void Camera::update(int playerX, int playerY, bool grounded) {
	x = playerX - 400;
	if(grounded) y = playerY - 300;
	y = playerY - 300;

	if (x < 64) x = 64;
	if (x > 1760) x = 1760;
	if (y < 0) y = 0;
	if (y > 1960) y = 1960;
}
