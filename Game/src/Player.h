#pragma once
#include"DrawUtils.h"
#include"Sprite.h"

class Player : public Sprite {
public:
	Player();
	int update(char l, char r, char u, char d, int deltatime);
	int update(int deltatime);
private:
	AnimationData idle;
	AnimationData run;
};
