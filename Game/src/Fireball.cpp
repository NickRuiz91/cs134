#include"Fireball.h"
#include"DrawUtils.h"

Fireball::Fireball(float x, float y, bool reverse) {
	FrameDef fd1(glTexImageTGAFile("assets/projectiles/fireball1.tga", &(size[0]), &(size[1])), .28f);
	FrameDef fd2(glTexImageTGAFile("assets/projectiles/fireball2.tga", &(size[0]), &(size[1])), .28f);
	FrameDef fd3(glTexImageTGAFile("assets/projectiles/fireball3.tga", &(size[0]), &(size[1])), .28f);
	FrameDef fd4(glTexImageTGAFile("assets/projectiles/fireball4.tga", &(size[0]), &(size[1])), .28f);

	AnimationDef fireball;
	fireball.addFrame(fd1);
	fireball.addFrame(fd2);
	fireball.addFrame(fd3);
	fireball.addFrame(fd4);

	AnimationData *fb = new AnimationData(fireball, .0f, 0);
	curDef = fb;

	position.x = x;
	position.y = y;

	range = 1000.0f;

	box = { x, y, getXSize() * scale, getYSize() * scale };

	float dir = 5.0f;
	float accel = 10.0f;
	if (reverse) {
		dir *= -1;
		accel *= -1;
	}

	velocity = Vector2(dir, 0.0f);
	acceleration = Vector2(accel, 0.0f);

	startingPos = position;

	speed = 2;

	damage = 20;
	
}

void Fireball::update() {
	position += velocity * speed + acceleration;
	box.x = position.x;
	box.y = position.y;

	if ((position - startingPos).mag() > range) {
		active = false;
	}
}

void Fireball::render(int camx, int camy) {
	glDrawSprite(getImage(), position.x - camx, position.y - camy, getXSize() * scale, getYSize() * scale, getReverse());
}

void Fireball::collisionResolution(AABB box2) {
	if(box2.tag != "player") active = false;
}
