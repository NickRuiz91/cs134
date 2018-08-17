#pragma once
#include"Sprite.h"
#include"GameObject.h"
#include"Collision.h"
#include"Vector2.h"
#include"DrawUtils.h"
#include"Projectile.h"
#include<list>

class Enemy : public Sprite, public GameObject, public Collision {
public:
	int health = 100;
	int damage = 10;
	bool alive = true;
	Vector2 velocity;
	int scale = 4;
	void render(int camx, int camy);
	bool isAlive() { return alive; }
	virtual void update(int xpos, int ypos, std::list<std::shared_ptr<Enemy>> &enemies, std::list<std::shared_ptr<Projectile>> &projectiles, std::list<std::shared_ptr<Collision>> &collidables) = 0;
	void hit(int damage) { health -= damage; }
	int getDamage() { return damage; }
};
