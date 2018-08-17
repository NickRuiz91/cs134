#pragma once
#include"DrawUtils.h"
#include"Vector2.h"
#include"Collision.h"
#include<string>

class Tile {
private:
	GLuint image;
	AABB box;
	int height;
	int width;
	std::string tag;
	Vector2 position;
	bool collision;
public:
	Tile();
	Tile(GLuint image, bool collision, std::string tag);
	GLuint getImage();
	int getWidth();
	int getHeight();
	void setHeight(int height);
	void setWidth(int width);
	bool getCollision();
	void setImage(GLuint image);
	void setCollision(bool collision);
	void setPos(int x, int y);
	AABB getAABB();
	void setTag(std::string t);
	std::string getTag();
};

class Background {
private:
	//Tile tiles[25][20];
	Tile tiles[22];
public:
	Background();
	void loadBackground();
	void DrawBackground(int camx, int camy);
	Tile getTile(int x, int y);
	int getWidth();
	int getHeight();
};
