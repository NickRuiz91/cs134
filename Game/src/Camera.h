#pragma once

class Camera {
private:
	int x;
	int y;
public:
	Camera();
	int getX();
	int getY();
	void update(int playerX, int playerY, bool grounded = true);
};
