#pragma once
#include"DrawUtils.h"
#include"Sprite.h"
#include"Vector2.h"
#include"Collision.h"
#include"Background.h"
#include"GameObject.h"
#include"Projectile.h"
#include<list>

class Player : public Sprite, public GameObject, public Collision {
public:
	Player();
	~Player();
	int getX();
	int getY();
	bool onscreen(int camx, int camy) { return true; }
	void render(int camx, int camy) override;
	Vector2 getPosition();
	void setPosition(Vector2 pos);
	void collisionResolution(AABB box2);
	float getYVelocity();
	int update(const unsigned char* keys, unsigned char prev[512], std::list<std::shared_ptr<Projectile>> &proj);
	bool isDescending();
	void destroyedEnemy();
	void hit(int damage);
	int getLives() const { return lives; }
	bool getWin() { return win; }
	void reset();
private:
	Vector2 velocity;
	Vector2 acceleration;
	AnimationData idle;
	AnimationData run;
	AnimationData jump;
	int speed = 8;
	float jump_size = 40.0;
	int scale = 3;
	int lives = 3;
	int invinc_frames = 0;
	bool invincible = false;
	bool win = false;
};
