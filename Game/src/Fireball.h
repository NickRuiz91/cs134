#pragma once
#include"Projectile.h"
#include"Collision.h"

class Fireball : public Projectile {
public:
	Fireball() {}
	Fireball(float x, float y, bool reverse);
	~Fireball() {}
	bool onscreen(int camx, int camy) { return true; }
	void render(int camx, int camy);
	void collisionResolution(AABB box2);
	void update();
private:
	int scale = 4;
};
