#pragma once
#include<string>
struct AABB {
	float x;
	float y;
	int w;
	int h;
	std::string tag;
};

class Collision {
public:
	bool collidedWith(AABB box2);
	virtual void collisionResolution(AABB box2) = 0;
	AABB getAABB() { return box; }
	static bool collided(float box1x, float box1y, float box1h, float box1w, float box2x, float box2y, float box2h, float box2w);
	AABB box;
	AABB oldPos;
	bool grounded = true;
	virtual void hit(int damage) = 0;
	bool isGrounded() { return grounded; }
	void setGrounded(bool ground) { grounded = ground; }
};
