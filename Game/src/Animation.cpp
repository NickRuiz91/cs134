#include"Animation.h"

// FrameDef
FrameDef::FrameDef(GLuint i, float fts) {
	image = i;
	frameTimeSecs = fts;
}

float FrameDef::getFrameTime() {
	return frameTimeSecs;
}

GLuint FrameDef::getImage() {
	return image;
}

// AnimationDef
AnimationDef::AnimationDef() {
	frames = {};
}

void AnimationDef::addFrame(FrameDef frame) {
	frames.push_back(frame);
}

FrameDef AnimationDef::getCurFrame(int cur) {
	return frames.at(cur);
}

int AnimationDef::getFramesSize() {
	return frames.size();
}

// Animation Data
AnimationData::AnimationData(AnimationDef ad, float secsUntilNextFrame, int curFrame) {
	def = ad;
	this->secsUntilNextFrame = secsUntilNextFrame;
	this->curFrame = curFrame;
}

int AnimationData::AnimUpdate(float deltaTime) {
	secsUntilNextFrame -= deltaTime;
	while (secsUntilNextFrame <= 0) {
		secsUntilNextFrame += def.getCurFrame(curFrame).getFrameTime();
		curFrame++;
		if (curFrame >= def.getFramesSize()) {
			curFrame = 0;
			//return 1;
		}
	}
	return 0;
}

int AnimationData::AnimDraw(int x, int y) {
	return 0;
}

GLuint AnimationData::getImage() {
	return def.getCurFrame(curFrame).getImage();
}
