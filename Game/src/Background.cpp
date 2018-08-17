#include"Background.h"

enum Type
{
	SKY = 0,
	GROUND = 1,
	BRICK = 2,
	CLOUD1 = 3,
	CLOUD2 = 4,
	CLOUD3 = 5,
	CLOUD4 = 6,
	PIPE1 = 7,
	PIPE2 = 8,
	PIPE3 = 9,
	PIPE4 = 10,
	HILL1 = 11,
	HILL2 = 12,
	HILL3 = 13,
	HILL4 = 14,
	HILL5 = 15,
	HILL6 = 16,
	BUSH1 = 17,
	BUSH2 = 18,
	BUSH3 = 19,
	QUESTION = 20,
	BLOCK = 21
};

int level[40][40] = {
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,20,0,0,2},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,8,0,0,0,0,0,16,0,0,0,0,0,0,0,0,2},
	{1,0,0,0,0,0,0,0,0,17,18,19,0,0,0,0,0,0,0,0,0,0,0,9,10,0,0,0,0,11,12,15,0,0,0,0,0,0,0,2},
	{1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2},
	{1,0,0,0,21,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
	{1,21,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
	{1,0,21,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
	{1,0,21,21,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,4,0,0,0,0,0,2},
	{1,0,0,0,21,0,0,0,0,21,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,6,0,0,0,0,0,2},
	{1,0,0,3,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,21,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
	{1,0,0,5,6,21,0,21,0,0,0,0,21,0,0,0,21,0,0,0,0,0,0,0,0,21,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,21,0,0,0,0,0,0,0,0,21,0,0,0,0,0,0,21,0,0,0,0,0,0,0,0,0,2},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,21,0,0,0,0,0,0,0,0,0,0,0,21,0,0,0,0,0,0,0,0,0,0,0,0,2},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,21,0,0,0,0,0,0,0,0,0,0,0,0,0,0,21,0,0,0,0,0,0,0,0,2},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,21,0,0,0,0,0,0,0,0,0,0,0,0,0,0,21,0,21,0,0,0,0,0,2},
	{1,0,0,0,0,0,0,0,0,0,0,0,16,0,0,0,0,21,0,0,0,0,0,0,0,0,0,0,21,0,0,0,21,0,0,21,0,0,21,2},
	{1,0,0,0,0,0,0,0,0,0,0,11,14,15,0,0,0,0,0,7,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
	{1,0,0,0,0,17,18,19,0,0,11,12,13,14,15,0,0,0,0,9,10,0,0,0,0,0,0,0,0,17,18,19,0,0,0,0,21,0,0,2},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,2},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,21,2},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,21,21,2},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,21,0,2},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,21,21,0,2},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,21,0,21,21,0,0,0,0,21,21,21,21,0,0,0,0,0,0,21,21,21,21,21,21,0,2},
	{1,0,0,0,0,3,4,0,0,0,0,21,0,0,0,0,0,0,0,0,21,21,21,0,0,21,21,21,0,0,21,21,21,0,0,0,0,0,0,2},
	{1,0,0,0,0,5,6,0,0,0,0,0,21,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
	{1,0,0,0,0,0,0,0,0,0,0,0,21,21,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
	{1,0,0,0,0,0,0,0,0,0,0,0,21,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,21,21,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,21,21,0,0,0,21,21,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,21,21,21,0,0,0,21,21,21,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,21,21,21,21,0,0,0,21,21,21,21,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,21,21,21,21,21,0,0,0,21,21,21,21,21,0,0,0,7,8,0,0,0,0,0,0,0,2},
	{1,0,0,0,0,0,0,0,17,18,19,0,0,21,21,21,21,21,21,16,0,0,21,21,21,21,21,21,0,0,9,10,0,0,0,0,17,18,19,2},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,12,15,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2}
};

Tile::Tile() {
	image = -1;
	height = -1;
	width = -1;
	collision = false;
	tag = "";
}

Tile::Tile(GLuint image, bool collision, std::string id) {
	this->image = image;
	this->collision = collision;
	this->tag = id;
}

GLuint Tile::getImage() {
	return image;
}

int Tile::getWidth() {
	return width;
}

int Tile::getHeight() {
	return height;
}

bool Tile::getCollision() {
	return collision;
}

void Tile::setImage(GLuint image) {
	this->image = image;
}

void Tile::setCollision(bool collision) {
	this->collision = collision;
}

void Tile::setHeight(int height) {
	box.h = height;
	this->height = height;
}

void Tile::setWidth(int width) {
	box.w = width;
	this->width = width;
}

void Tile::setPos(int x, int y) {
	box.x = x;
	box.y = y;
}

AABB Tile::getAABB() {
	return box;
}

void Tile::setTag(std::string t) {
	tag = t;
	box.tag = t;
}

std::string Tile::getTag() {
	return tag;
}

void Background::loadBackground() {

	int height = -1;
	int width = -1;
	int scale = 4;

	Tile sky;
	sky.setImage(glTexImageTGAFile("assets/background/sky.tga", &width, &height));
	sky.setCollision(false);
	sky.setHeight(height * scale);
	sky.setWidth(width * scale);
	sky.setTag("sky");

	Tile ground;
	ground.setImage(glTexImageTGAFile("assets/background/ground.tga", &width, &height));
	ground.setCollision(true);
	ground.setHeight(height * scale);
	ground.setWidth(width * scale);
	ground.setTag("ground");

	Tile brick;
	brick.setImage(glTexImageTGAFile("assets/background/brick.tga", &width, &height));
	brick.setCollision(true);
	brick.setHeight(height * scale);
	brick.setWidth(width * scale);
	brick.setTag("brick");

	Tile cloud1;
	cloud1.setImage(glTexImageTGAFile("assets/background/cloud1.tga", &width, &height));
	cloud1.setCollision(false);
	cloud1.setHeight(height * scale);
	cloud1.setWidth(width * scale);
	cloud1.setTag("cloud1");

	Tile cloud2;
	cloud2.setImage(glTexImageTGAFile("assets/background/cloud2.tga", &width, &height));
	cloud2.setCollision(false);
	cloud2.setHeight(height * scale);
	cloud2.setWidth(width * scale);
	cloud2.setTag("cloud2");

	Tile cloud3;
	cloud3.setImage(glTexImageTGAFile("assets/background/cloud3.tga", &width, &height));
	cloud3.setCollision(false);
	cloud3.setHeight(height * scale);
	cloud3.setWidth(width * scale);
	cloud3.setTag("cloud3");

	Tile cloud4;
	cloud4.setImage(glTexImageTGAFile("assets/background/cloud4.tga", &width, &height));
	cloud4.setCollision(false);
	cloud4.setHeight(height * scale);
	cloud4.setWidth(width * scale);
	cloud4.setTag("cloud4");

	Tile bush1;
	bush1.setImage(glTexImageTGAFile("assets/background/bush1.tga", &width, &height));
	bush1.setCollision(false);
	bush1.setHeight(height * scale);
	bush1.setWidth(width * scale);
	bush1.setTag("bush1");

	Tile bush2;
	bush2.setImage(glTexImageTGAFile("assets/background/bush2.tga", &width, &height));
	bush2.setCollision(false);
	bush2.setHeight(height * scale);
	bush2.setWidth(width * scale);
	bush2.setTag("bush2");

	Tile bush3;
	bush3.setImage(glTexImageTGAFile("assets/background/bush3.tga", &width, &height));
	bush3.setCollision(false);
	bush3.setHeight(height * scale);
	bush3.setWidth(width * scale);
	bush3.setTag("bush3");

	Tile hill1;
	hill1.setImage(glTexImageTGAFile("assets/background/hill1.tga", &width, &height));
	hill1.setCollision(false);
	hill1.setHeight(height * scale);
	hill1.setWidth(width * scale);
	hill1.setTag("hill1");

	Tile hill2;
	hill2.setImage(glTexImageTGAFile("assets/background/hill2.tga", &width, &height));
	hill2.setCollision(false);
	hill2.setHeight(height * scale);
	hill2.setWidth(width * scale);
	hill2.setTag("hill2");

	Tile hill3;
	hill3.setImage(glTexImageTGAFile("assets/background/hill3.tga", &width, &height));
	hill3.setCollision(false);
	hill3.setHeight(height * scale);
	hill3.setWidth(width * scale);
	hill3.setTag("hill3");

	Tile hill4;
	hill4.setImage(glTexImageTGAFile("assets/background/hill4.tga", &width, &height));
	hill4.setCollision(false);
	hill4.setHeight(height * scale);
	hill4.setWidth(width * scale);
	hill4.setTag("hill4");

	Tile hill5;
	hill5.setImage(glTexImageTGAFile("assets/background/hill5.tga", &width, &height));
	hill5.setCollision(false);
	hill5.setHeight(height * scale);
	hill5.setWidth(width * scale);
	hill5.setTag("hill5");

	Tile hill6;
	hill6.setImage(glTexImageTGAFile("assets/background/hill6.tga", &width, &height));
	hill6.setCollision(false);
	hill6.setHeight(height * scale);
	hill6.setWidth(width * scale);
	hill6.setTag("hill6");

	Tile pipe1;
	pipe1.setImage(glTexImageTGAFile("assets/background/pipe1.tga", &width, &height));
	pipe1.setCollision(true);
	pipe1.setHeight(height * scale);
	pipe1.setWidth(width * scale);
	pipe1.setTag("pipe1");

	Tile pipe2;
	pipe2.setImage(glTexImageTGAFile("assets/background/pipe2.tga", &width, &height));
	pipe2.setCollision(true);
	pipe2.setHeight(height * scale);
	pipe2.setWidth(width * scale);
	pipe2.setTag("pipe2");

	Tile pipe3;
	pipe3.setImage(glTexImageTGAFile("assets/background/pipe3.tga", &width, &height));
	pipe3.setCollision(true);
	pipe3.setHeight(height * scale);
	pipe3.setWidth(width * scale);
	pipe3.setTag("pipe3");

	Tile pipe4;
	pipe4.setImage(glTexImageTGAFile("assets/background/pipe4.tga", &width, &height));
	pipe4.setCollision(true);
	pipe4.setHeight(height * scale);
	pipe4.setWidth(width * scale);
	pipe4.setTag("pipe4");

	Tile question;
	question.setImage(glTexImageTGAFile("assets/background/question.tga", &width, &height));
	question.setCollision(true);
	question.setHeight(height * scale);
	question.setWidth(width * scale);
	question.setTag("question");

	Tile block;
	block.setImage(glTexImageTGAFile("assets/background/block.tga", &width, &height));
	block.setCollision(true);
	block.setHeight(height * scale);
	block.setWidth(width * scale);
	block.setTag("block");

	tiles[0] = sky;
	tiles[1] = ground;
	tiles[2] = brick;
	tiles[3] = cloud1;
	tiles[4] = cloud2;
	tiles[5] = cloud3;
	tiles[6] = cloud4;
	tiles[7] = pipe1;
	tiles[8] = pipe2;
	tiles[9] = pipe3;
	tiles[10] = pipe4;
	tiles[11] = hill1;
	tiles[12] = hill2;
	tiles[13] = hill3;
	tiles[14] = hill4;
	tiles[15] = hill5;
	tiles[16] = hill6;
	tiles[17] = bush1;
	tiles[18] = bush2;
	tiles[19] = bush3;
	tiles[20] = question;
	tiles[21] = block;
}

Background::Background() {
	loadBackground();
}

Tile Background::getTile(int x, int y) {
	if (x >= 40 || y >= 40 || x < 0 || y < 0) return tiles[0];
	return tiles[level[x][y]];
}

int Background::getHeight() {
	return tiles[level[0][0]].getHeight();
}

int Background::getWidth() {
	return tiles[level[0][0]].getWidth();
}

void Background::DrawBackground(int camx, int camy) {
	for (int i = camx / getWidth(); i < camx / getWidth() + 14; i++) {
		for (int j = camy / getHeight(); j < camy / getHeight() + 11; j++) {
			glDrawSprite(getTile(j, i).getImage(), getWidth() * i - camx, getHeight() * j - camy, getWidth(), getHeight());
		}
	}
}
