#pragma once
#include"Enemy.h"

class Spiny : public Enemy {
public:
	~Spiny();
	Spiny(float xpos, float ypos, bool rev);
	void collisionResolution(AABB box2);
	AnimationData *walk;
	void update(int xpos, int ypos, std::list<std::shared_ptr<Enemy>> &enemies, std::list<std::shared_ptr<Projectile>> &projectiles, std::list<std::shared_ptr<Collision>> &collidables);
};
