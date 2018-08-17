#pragma once
#include<string>
#include"Vector2.h"
#include"GameObject.h"
#include"Sprite.h"
#include"Collision.h"

class Projectile : public GameObject, public Sprite, public Collision {
public:
	int range;
	int speed;
	int damage;
	Vector2 startingPos;
	Vector2 velocity;
	Vector2 acceleration;
	std::string id;
	bool active = true;
	bool isActive() { return active; }
	void render(int camx, int camy);
	virtual void update() = 0;
	int scale;
	void hit(int damage) {}
};
