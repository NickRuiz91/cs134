#pragma once
#include <string>

class Level
{
public:

	Level(std::string tID, int ms, int ts);
	~Level();

	void LoadMap(std::string path, int sizeX, int sizeY);
	void AddTile(int srcX, int srcY, int xpos, int ypos);

private:
	std::string texID;
	int mapScale;
	int tileSize;
	int scaledSize;

};
