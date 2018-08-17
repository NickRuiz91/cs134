#pragma once
#include"Enemy.h"

class Lakitu : public Enemy {
public:
	Lakitu(int xpos, int ypos);
	int getX() { return position.x; };
	int getY() { return position.y; }
	void collisionResolution(AABB box2) {}
	void update(int xpos, int ypos, std::list<std::shared_ptr<Enemy>> &enemies, std::list<std::shared_ptr<Projectile>> &projectiles, std::list<std::shared_ptr<Collision>> &collidables);
	int time;
	bool follow = false;
};
