#include"Spiny.h"

Spiny::Spiny(float xpos, float ypos, bool rev) {
	FrameDef fd(glTexImageTGAFile("assets/enemies/spiny1.tga", &(size[0]), &(size[1])), .11f);
	FrameDef fd2(glTexImageTGAFile("assets/enemies/spiny2.tga", &(size[0]), &(size[1])), .11f);
	AnimationDef adef_fall;
	adef_fall.addFrame(fd);
	adef_fall.addFrame(fd2);


	FrameDef fd3(glTexImageTGAFile("assets/enemies/spiny3.tga", &(size[0]), &(size[1])), .11f);
	FrameDef fd4(glTexImageTGAFile("assets/enemies/spiny4.tga", &(size[0]), &(size[1])), .11f);

	AnimationDef adef_walk;
	adef_walk.addFrame(fd3);
	adef_walk.addFrame(fd4);

	AnimationData *ad_fall = new AnimationData(adef_fall, .0f, 0);
	AnimationData *ad_walk = new AnimationData(adef_walk, .0f, 0);
	curDef = ad_fall;
	walk = ad_walk;

	position = Vector2(xpos, ypos);
	velocity = Vector2(1, 6);
	if (rev) {
		reverse = true;
		velocity.x *= -1;
	}

	box.x = position.x;
	box.y = position.y;

	box.h = getYSize() * scale;
	box.w = getXSize() * scale;

	box.tag = "spiny";

	health = 100;

	grounded = false;
	if (rev) reverse = true;
}

Spiny::~Spiny() {
	delete walk;
}

void Spiny::update(int xpos, int ypos, std::list<std::shared_ptr<Enemy>> &enemies, std::list<std::shared_ptr<Projectile>> &projectiles, std::list<std::shared_ptr<Collision>> &collidables) {
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
		position.y= 4000;
	}

	if (position.y > 5000) alive = false;

	box.x = position.x;
	box.y = position.y;
}

void Spiny::collisionResolution(AABB box2) {
	bool walkable = false;
	if (box2.tag == "ground" || box2.tag == "block" || box2.tag == "question" || box2.tag == "brick" || box2.tag == "pipe1" || box2.tag == "pipe2") walkable = true;

	bool above = oldPos.y + oldPos.h < box2.y && box.y + box.h >= box2.y;
	bool below = oldPos.y > box2.y + box2.h && box.y < box2.y + box2.h;
	bool right = box.x + box.w > box2.x && oldPos.x < box2.x;
	bool left = box.x <= box2.x + box2.w && oldPos.x > box2.x + box2.w;

	if (above && walkable) {
		curDef = walk;
		position.y = box2.y - box.h - 1;
		grounded = true;
	}
	else if (below) {
		position.y = box2.y + box2.h + 1;
		velocity.y = 0;
	}
	else if (left) {
		position.x = box2.x + box2.w + 11;
		velocity.x *= -1;
	}
	else if (right) {
		velocity.x *= -1;
		position.x = box2.x - box.w;
	}


	box.x = position.x;
	box.y = position.y;
}