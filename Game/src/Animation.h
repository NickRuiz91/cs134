#pragma once
#include<vector>
#include"GL/glew.h"

class FrameDef {
private:
	GLuint image;
	float frameTimeSecs;
public:
	FrameDef(GLuint i, float fts) : image(i), frameTimeSecs(fts) {}
	float getFrameTime();
	GLuint getImage();
};

class AnimationDef {
private:
	std::vector<FrameDef> frames;
public:
	AnimationDef();
	void addFrame(FrameDef frame);
	FrameDef getCurFrame(int cur);
	int getFramesSize();
};

class AnimationData {
private:
	AnimationDef def;
	int curFrame;
	float secsUntilNextFrame;
public:
	AnimationData() {}
	AnimationData(AnimationDef def, float secsUntilNextFrame, int curFrame = 0);
	int AnimUpdate(float deltaTime);
	int AnimDraw(int x, int y);
	GLuint getImage();
};
