#include<SDL.h>
#include"Player.h"
#include"Fireball.h"

Player::Player() {
	// player idle
	FrameDef fd(glTexImageTGAFile("assets/sprites/player/idle/idle.tga", &(size[0]), &(size[1])), .09f);

	AnimationDef adef_idle;
	adef_idle.addFrame(fd);

	// player run
	FrameDef fd9(glTexImageTGAFile("assets/sprites/player/run/run1.tga", &(size[0]), &(size[1])), .28f);
	FrameDef fd10(glTexImageTGAFile("assets/sprites/player/run/run2.tga", &(size[0]), &(size[1])), .28f);
	FrameDef fd11(glTexImageTGAFile("assets/sprites/player/run/run3.tga", &(size[0]), &(size[1])), .28f);

	AnimationDef adef_run;
	adef_run.addFrame(fd9);
	adef_run.addFrame(fd10);
	adef_run.addFrame(fd11);

	FrameDef fd12(glTexImageTGAFile("assets/sprites/player/jump/jump.tga", &(size[0]), &(size[1])), .09f);

	AnimationDef adef_jump;
	adef_jump.addFrame(fd12);

	AnimationData ad_idle(adef_idle, .1f, 0);
	AnimationData ad_run(adef_run, .0f, 0);
	AnimationData ad_jump(adef_jump, .0f, 0);

	idle = ad_idle;
	run = ad_run;
	jump = ad_jump;
	curDef = &idle;

	position = Vector2(200, 2399);
	velocity = Vector2(.0f, .0f);
	acceleration = Vector2(.2f, 3.7f);

	box.x = position.x;
	box.y = position.y;
	box.w = getXSize() * scale;
	box.h = getYSize() * scale;

	oldPos = box;

	box.tag = "player";
}

Player::~Player() {
}

int Player::getX() {
	return (int)position.x;
}

int Player::getY() {
	return (int)position.y;
}

void Player::render(int camx, int camy) {
	glDrawSprite(getImage(), position.x - camx, position.y - camy, getXSize() * scale, getYSize() * scale, getReverse());
}

Vector2 Player::getPosition() {
	return position;
}

void Player::setPosition(Vector2 pos) {
	position = pos;
}

void Player::collisionResolution(AABB box2) {

	if (box2.tag == "question") win = true;

	if ((box2.tag == "goomba" || box2.tag == "lakitu" || box2.tag == "spiny") && invinc_frames == 0) {
		velocity.x *= -.5;
		lives--;
		invincible = true;
		invinc_frames = 40;

	}

	bool walkable = false;
	if (box2.tag == "ground" || box2.tag == "block" || box2.tag == "question" || box2.tag == "brick" || box2.tag == "pipe1" || box2.tag == "pipe2") walkable = true;

	bool above = oldPos.y + oldPos.h < box2.y && box.y + box.h > box2.y;
	bool below = oldPos.y > box2.y + box2.h && box.y < box2.y + box2.h;
	bool right = (box.y < box2.y || box.y + box.h > box2.y + box2.h) && box.x + box.w > box2.x && oldPos.x < box2.x;
	bool left = (box.y < box2.y || box.y + box.h > box2.y + box2.h) && box.x < box2.x + box2.w && oldPos.x > box2.x + box2.w;


	if (above && walkable) {
		position.y = box2.y - box.h - 1;
		grounded = true;
	}
	else if (below) {
		position.y = box2.y + box2.h + 1;
		velocity.y = 0;
	}
	else if (right) {
		position.x = box2.x - box.w - 1;
	}
	else if (left) {
		position.x = box2.x + box2.w + 1;
	}

	box.x = position.x;
	box.y = position.y;
}

float Player::getYVelocity() {
	return velocity.y;
}

int Player::update(const unsigned char* keys, unsigned char prev[512], std::list<std::shared_ptr<Projectile>> &proj) {

	char up = keys[SDL_SCANCODE_UP];
	char prevJump = prev[SDL_SCANCODE_UP];
	char left = keys[SDL_SCANCODE_LEFT];
	char prevLeft = prev[SDL_SCANCODE_LEFT];
	char right = keys[SDL_SCANCODE_RIGHT];
	char prevRight = prev[SDL_SCANCODE_RIGHT];
	char shoot = keys[SDL_SCANCODE_SPACE];
	char prevShoot = prev[SDL_SCANCODE_SPACE];
	char r = keys[SDL_SCANCODE_R];

	if (r) {
		position.reassign(100, 2399);
		velocity.reassign(0, 0);
	}

	if (invincible) {
		invinc_frames--;
		if (invinc_frames <= 0) {
			invincible = false;
			invinc_frames = 0;
		}
	}

	oldPos = box;

	if (grounded) velocity.y = 0;

	if (left) {
		if (grounded) {
			velocity.x -= acceleration.x;
			if (velocity.x < -1.5f) velocity.x = -1.5f;
			position.x += velocity.x * speed;
			curDef = &run;
		}
		else {
			position.x += velocity.x / 1.0f * speed;
		}
		reverse = true;
	}

	if (right) {
		if (grounded) {
			velocity.x += acceleration.x;
			if (velocity.x > 1.5f) velocity.x = 1.5f;
			position.x += velocity.x * speed;
			curDef = &run;
		}
		else {
			position.x += velocity.x / 1.0f * speed;
		}
		reverse = false;
	}

	if (velocity.x > 5) velocity.x = 5;
	if (velocity.x < -5) velocity.x = -5;

	if (!grounded) {
		position.y -= velocity.y;
		velocity.y -= acceleration.y;
	}

	if (!(left || right)) {
		velocity.x = 0.0f;
		curDef = &idle;
	}

	if (up && grounded) {
		position.y -= 10.0f;
		velocity.y = jump_size;
		grounded = false;
		curDef = &jump;
	}

	if (shoot && !prevShoot) {

		if (reverse) {
			std::shared_ptr<Fireball> f(new Fireball(position.x - 10, position.y + 20, reverse));
			proj.push_back(f);
		}
		else {
			std::shared_ptr<Fireball> f(new Fireball(position.x + 20, position.y + 20, reverse));
			proj.push_back(f);
		}
	}

	if (velocity.y > 30 ) velocity.y = 30;
	if (position.x < 64) position.x = 64;
	if (position.y > 4000) {
		position.reassign(100, 2399);
		lives--;
	}

	box.x = position.x;
	box.y = position.y;

	return 0;
}

bool Player::isDescending() {
	return velocity.y < -8.4f;
}

void Player::destroyedEnemy() {
	velocity.y = jump_size / 2;
}

void Player::hit(int damage) {
}

void Player::reset() {
	position.reassign(200, 2399);
	lives = 3;
	invincible = false;
	invinc_frames = 0;
	velocity.reassign(0, 0);
	win = false;
}