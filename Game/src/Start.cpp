#include"Start.h"
#include"DrawUtils.h"

startscreen::Start::Start() {

	int height = -1;
	int width = -1;


	tiles[0] = Tile{ glTexImageTGAFile("assets/start/start1.tga", &width, &height), 0, 0, 200, 200 };
	tiles[1] = Tile{ glTexImageTGAFile("assets/start/start2.tga", &width, &height), 200, 0, 200, 200 };
	tiles[2] = Tile{ glTexImageTGAFile("assets/start/start3.tga", &width, &height), 400, 0, 200, 200 };
	tiles[3] = Tile{ glTexImageTGAFile("assets/start/start4.tga", &width, &height), 600, 0, 200 };
	tiles[4] = Tile{ glTexImageTGAFile("assets/start/start5.tga", &width, &height), 0, 200, 200, 200 };
	tiles[5] = Tile{ glTexImageTGAFile("assets/start/start6.tga", &width, &height), 200, 200, 200, 200 };
	tiles[6] = Tile{ glTexImageTGAFile("assets/start/start7.tga", &width, &height), 400, 200, 200, 200 };
	tiles[7] = Tile{ glTexImageTGAFile("assets/start/start8.tga", &width, &height), 600, 200, 200, 200 };
	tiles[8] = Tile{ glTexImageTGAFile("assets/start/start9.tga", &width, &height), 0, 400, 200, 200 };
	tiles[9] = Tile{ glTexImageTGAFile("assets/start/start10.tga", &width, &height), 200, 400, 200, 200 };
	tiles[10] = Tile{ glTexImageTGAFile("assets/start/start11.tga", &width, &height), 400, 400, 200, 200 };
	tiles[11] = Tile{ glTexImageTGAFile("assets/start/start12.tga", &width, &height), 600, 400, 200, 200 };
}

void startscreen::Start::render() {

	for (int i = 0; i < 12; i++) {
		glDrawSprite(tiles[i].image, tiles[i].x, tiles[i].y, tiles[i].w, tiles[i].h, false);
	}
}

startscreen::Hud::Hud() {

	int height = -1;
	int width = -1;

	tiles[0] = Tile{ glTexImageTGAFile("assets/hud/text.tga", &width, &height), 10, 0, 100, 50 };
	tiles[1] = Tile{ glTexImageTGAFile("assets/hud/lives.tga", &width, &height), 2, 50, 17, 16 };
}

void startscreen::Hud::render(int lives) {

	glDrawSprite(tiles[0].image, tiles[0].x, tiles[0].y, tiles[0].w, tiles[0].h, false);

	int scale = 3;
	int x = lives;
	if (lives > 5) x = 5;

	for (int i = 0; i < x; i++) {
		glDrawSprite(tiles[1].image, tiles[1].x * tiles[1].w * i, tiles[1].y, tiles[1].w * scale, tiles[1].h * scale, false);
	}
}

startscreen::GameOver::GameOver() {

	int height = -1;
	int width = -1;

	lose = Tile{ glTexImageTGAFile("assets/hud/gameover.tga", &width, &height), 200, 100, 400, 200 };
	win = Tile{ glTexImageTGAFile("assets/end/end.tga", &width, &height), 200, 100, 400, 200 };
}

void startscreen::GameOver::renderLoss() {

	glDrawSprite(lose.image, lose.x, lose.y, lose.w, lose.h, false);
}

void startscreen::GameOver::renderWin() {

	glDrawSprite(win.image, win.x, win.y, win.w, win.h, false);
}
