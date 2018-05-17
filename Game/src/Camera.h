#pragma once
#ifndef CAMERA_H
#define CAMERA_H

typedef struct {
	int x;
	int y;
} Camera;

void CameraUpdate(Camera *c, char a, char s, char d, char w, int deltatime, int space, int playerX, int playerY);

#endif