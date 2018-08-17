#pragma once
#include"Enemy.h"

class Goomba : public Enemy {
public:
	Goomba(int xpos, int ypos);
	~Goomba();
	int getX();
	int getY();
	void collisionResolution(AABB box2);
	void update(int xpos, int ypos, std::list<std::shared_ptr<Enemy>> &enemies, std::list<std::shared_ptr<Projectile>> &projectiles, std::list<std::shared_ptr<Collision>> &collidables);
};
