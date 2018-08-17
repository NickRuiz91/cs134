#include"Goomba.h"
#include"DrawUtils.h"

Goomba::Goomba(int xpos, int ypos) {
	FrameDef fd(glTexImageTGAFile("assets/enemies/goomba.tga", &(size[0]), &(size[1])), .0001f);
	FrameDef fd2(glTexImageTGAFile("assets/enemies/goomba2.tga", &(size[0]), &(size[1])), .0001f);

	AnimationDef adef_run;
	adef_run.addFrame(fd);
	adef_run.addFrame(fd2);

	AnimationData *ad_run = new AnimationData(adef_run, .0f, 0);
	curDef = ad_run;
	
	position = Vector2(xpos, ypos);
	velocity = Vector2(2.5, 8);

	box.x = position.x;
	box.y = position.y;

	box.h = getYSize() * scale;
	box.w = getXSize() * scale;

	box.tag = "goomba";

	oldPos = box;

	health = 100;
}

Goomba::~Goomba() {
	delete curDef;
}

void Goomba::update(int xpos, int ypos, std::list<std::shared_ptr<Enemy>> &enemies, std::list<std::shared_ptr<Projectile>> &projectiles, std::list<std::shared_ptr<Collision>> &collidables) {

	oldPos = box;

	if (health <= 0) alive = false;

	if (alive) {
		position.x += velocity.x;

		if (!grounded) {
			position.y += velocity.y;
		}

		if (position.x < 64) {
			velocity.x *= -1;
		}
		if (position.x > 2000 - getXSize() * scale) {
			position.x = 2000 - getXSize() * scale;
			velocity.x *= -1;
		}

		if (velocity.x > 0) reverse = true;
		else reverse = false;
	}
	else {
		position.y = 4000;
	}

	box.x = position.x;
	box.y = position.y;
}

int Goomba::getX() {
	return position.x;
}

int Goomba::getY() {
	return position.y;
}

void Goomba::collisionResolution(AABB box2) {
	bool walkable = false;
	if (box2.tag == "ground" || box2.tag == "block" || box2.tag == "question" || box2.tag == "brick" || box2.tag == "pipe1" || box2.tag == "pipe2") walkable = true;

	bool above = oldPos.y + oldPos.h < box2.y && box.y + box.h >= box2.y;
	bool below = oldPos.y > box2.y + box2.h && box.y < box2.y + box2.h;
	bool right = box.x + box.w > box2.x && oldPos.x < box2.x;
	bool left = box.x < box2.x + box2.w && oldPos.x > box2.x + box2.w;


	if (above && walkable) {
		position.y = box2.y - box.h - 1;
		grounded = true;
	}
	else if (below) {
		position.y = box2.y + box2.h + 1;
		velocity.y = 0;
	}
	else if (right) {
		velocity.x *= -1;
		position.x = box2.x - box.w;
	}
	else if (left) {
		velocity.x *= -1;
		position.x = box2.x + box2.w + 3;
	}

	box.x = position.x;
	box.y = position.y;
}
