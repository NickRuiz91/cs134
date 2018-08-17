#pragma once
#include"GL/glew.h"

namespace startscreen {
	struct Tile {
		GLuint image;
		int x, y, w, h;
	};

	class Start {
	private:
		Tile tiles[12];
	public:
		Start();
		void render();
	};

	class Hud {
	private:
		Tile tiles[2];
	public:
		Hud();
		void render(int lives);
	};

	class GameOver {
	private:
		Tile lose;
		Tile win;
	public:
		GameOver();
		void renderWin();
		void renderLoss();
	};
}
