#include"Lakitu.h"
#include"Spiny.h"

Lakitu::Lakitu(int xpos, int ypos) {
	FrameDef fd(glTexImageTGAFile("assets/enemies/lakitu1.tga", &(size[0]), &(size[1])), .11f);

	AnimationDef adef_fly;
	adef_fly.addFrame(fd);

	AnimationData *ad_fly = new AnimationData(adef_fly, .0f, 0);
	curDef = ad_fly;

	position = Vector2(xpos, ypos);
	velocity = Vector2(2.5, 0);

	box.x = position.x;
	box.y = position.y;

	box.h = getYSize() * scale;
	box.w = getXSize() * scale;

	box.tag = "lakitu";

	health = 100;

	grounded = false;

	time = 0;
}

void Lakitu::update(int xpos, int ypos, std::list<std::shared_ptr<Enemy>> &enemies, std::list<std::shared_ptr<Projectile>> &projectiles, std::list<std::shared_ptr<Collision>> &collidables) {
	oldPos = box;

	time++;

	if (health <= 0) alive = false;

	if (follow) {

		if (std::abs(xpos - position.x) > 2) {

			if (xpos - position.x < 0 && velocity.x > 0) {
				velocity.x *= -1;
			}
			else if (xpos - position.x > 0 && velocity.x < 0) {
				velocity.x *= -1;
			}

			if (velocity.x < 0) velocity.x -= .15f;
			else if (velocity.x > 0) velocity.x += .15f;
			if (velocity.x > 2.5f)  velocity.x = 5.5f;
			if (velocity.x < -2.5f)  velocity.x = -5.5f;
			position.x += velocity.x;
		}

		if (time > 400 && std::abs(xpos - position.x) <= 10 && ypos - position.y < 100) {
			time = 0;
			std::shared_ptr<Spiny> s(new Spiny(position.x, position.y, !reverse));
			enemies.push_back(s);
			collidables.push_back(s);
		}
	}
	else if (alive) {
		position.x += velocity.x;

		if (position.x < 0) {
			velocity.x *= -1;
			position.x = 0;
		}
		if (position.x > 2000 - getXSize() * scale) {
			position.x = 2000 - getXSize() * scale;
			velocity.x *= -1;
		}
		if (std::abs(xpos - position.x) <= 20) {
			follow = true;
			
		}
	}
	else {
		position.y = 4000;
	}

	if (velocity.x > 0) reverse = true;
	else reverse = false;

	if (time > 10000) time = 100;

	box.x = position.x;
	box.y = position.y;
}
