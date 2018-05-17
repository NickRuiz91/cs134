#include"Player.h"

#define SIZE 1600

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

	AnimationData ad_idle(adef_idle, .1f, 0);
	AnimationData ad_run(adef_run, .0f, 0);

	idle = ad_idle;
	run = ad_run;
	curDef = &run;

	position[0] = 100;
	position[1] = 100;
}

int Player::update(char l, char r, char u, char d, int deltatime) {
	int speed = deltatime;
	if (r && u && position[0] < SIZE - size[0] && position[1] > 0) {
		position[0] += speed;
		position[1] -= speed;
		curDef = &run;
		reverse = false;
	}
	else if (r && d && position[0] < SIZE - size[0] && position[1] < SIZE - size[1]) {
		position[0] += speed;
		position[1] += speed;
		curDef = &run;
		reverse = false;
	}
	else if (l && u && position[0] > 0 && position[1] > 0) {
		position[0] -= speed;
		position[1] -= speed;
		curDef = &run;
		reverse = true;
	}
	else if (l && d && position[0] > 0 && position[1] < SIZE - size[1]) {
		position[0] -= speed;
		position[1] += speed;
		curDef = &run;
		reverse = true;
	}
	else if (l && position[0] > 0) {
		position[0] -= speed;
		curDef = &run;
		reverse = true;
	}
	else if (r && position[0] < SIZE - size[0]) {
		position[0] += speed;
		curDef = &run;
		reverse = false;
	}
	else if (u && position[1] > 0) {
		position[1] -= speed;
		curDef = &run;
	}
	else if (d && position[1] < SIZE - size[1]) {
		position[1] += speed;
		curDef = &run;
	}
	else curDef = &idle;

	if (position[0] < 0) position[0] = 0;
	if (position[0] > SIZE - size[0]) position[0] = SIZE - size[0];
	if (position[1] < 0) position[1] = 0;
	if (position[1] > SIZE - size[1]) position[1] = SIZE - size[1];

	return 0;
}

int Player::update(int deltatime) {
	return -1;
}
