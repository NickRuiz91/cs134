#define SDL_MAIN_HANDLED
#define GLEW_STATIC
#include<SDL.h>
#include<GL/glew.h>
#include<assert.h>
#include<iostream>
#include"DrawUtils.h"
#include"Player.h"
#include"Background.h"
#include"Camera.h"
#include"Projectile.h"
#include"Goomba.h"
#include"Lakitu.h"
#include"Collision.h"
#include"Spiny.h"
#include"Start.h"

// Set this to true to make the game loop exit.
bool shouldExit = false;

// The previous frame's keyboard state.
unsigned char kbPrevState[SDL_NUM_SCANCODES] = { 0 };

// The current frame's keyboard state.
const unsigned char* kbState = NULL;

std::shared_ptr<Player> pd;
std::list<std::shared_ptr<Projectile>> projectiles;
std::list<std::shared_ptr<Collision>> collidables;
std::list<std::shared_ptr<Enemy>> enemies;

void LoadEnemies() {

	projectiles.clear();
	collidables.clear();
	enemies.clear();

	std::shared_ptr<Goomba> g1(new Goomba(1000, 2380));
	std::shared_ptr<Goomba> g2(new Goomba(1555, 1370));
	std::shared_ptr<Goomba> g3(new Goomba(191, 1370));
	std::shared_ptr<Goomba> g4(new Goomba(2080, 350));
	std::shared_ptr<Lakitu> l(new Lakitu(1920, 832));
	std::shared_ptr<Spiny> s(new Spiny(700, 520, true));
	enemies.push_back(g1);
	enemies.push_back(g2);
	enemies.push_back(g3);
	enemies.push_back(g4);
	enemies.push_back(l);
	enemies.push_back(s);
	collidables.push_back(g1);
	collidables.push_back(g2);
	collidables.push_back(g3);
	collidables.push_back(g4);
	collidables.push_back(s);
	collidables.push_back(l);
	collidables.push_back(pd);
}

void reset() {
	LoadEnemies();
	pd->reset();
}

int main(void)
{
	// Initialize SDL.
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cerr << "Could not initialize SDL. ErrorCode=" << SDL_GetError() << std::endl;
		return 1;
	}

	// Create the window and OpenGL context.
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_Window* window = SDL_CreateWindow(
		"Game",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		800, 600,
		SDL_WINDOW_OPENGL);
	if (!window) {
		std::cerr << "Could not create window. ErrorCode=" << SDL_GetError() << std::endl;
		SDL_Quit();
		return 1;
	}
	SDL_GL_CreateContext(window);

	// Make sure we have a recent version of OpenGL.
	GLenum glewError = glewInit();
	if (glewError != GLEW_OK) {
		std::cerr << "Could not initialize glew. ErrorCode=" << glewGetErrorString(glewError) << std::endl;
		SDL_Quit();
		return 1;
	}
	if (GLEW_VERSION_2_0) {
		std::cerr << "OpenGL 2.0 or greater supported: Version=" << glGetString(GL_VERSION) << std::endl;
	}
	else {
		std::cerr << "OpenGL max supported version is too low." << std::endl;
		SDL_Quit();
		return 1;
	}

	// Setup OpenGL state.
	glViewport(0, 0, 800, 600);
	glMatrixMode(GL_PROJECTION);
	glOrtho(0, 800, 600, 0, 0, 100);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	// Game initialization goes here.
	
	pd = std::unique_ptr<Player>(new Player());

	LoadEnemies();
	//std::shared_ptr<Player> pd(new Player());

	Camera c;
	Background bd;

	//collidables.push_back(pd);

	const int FPS = 60;
	const int frameDelay = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;

	bool startscreen = true;
	bool over = false;
	bool win = false;

	startscreen::Start s;
	startscreen::Hud h;
	startscreen::GameOver go;

	// The game loop.
	kbState = SDL_GetKeyboardState(NULL);
	while (!shouldExit) {

		frameStart = SDL_GetTicks();

		assert(glGetError() == GL_NO_ERROR);
		memcpy(kbPrevState, kbState, sizeof(kbPrevState));

		// Handle OS message pump.
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT:
				shouldExit = true;
			}
		}

		// Game logic goes here.
		if (kbState[SDL_SCANCODE_ESCAPE]) {
			shouldExit = true;
		}

		if (startscreen) {

			if (kbState[SDL_SCANCODE_SPACE]) {
				over = false;
				startscreen = false;
				win = false;
				reset();
			}

			glClearColor(0, 0, 0, 1);
			glClear(GL_COLOR_BUFFER_BIT);


			s.render();

			frameTime = SDL_GetTicks() - frameStart;
		}
		else if (over) {

			if (kbState[SDL_SCANCODE_SPACE]) {
				startscreen = false;
				over = false;
				win = false;
				reset();
			}
			else if (kbState[SDL_SCANCODE_Q]) {
				startscreen = true;
				over = false;
				win = false;
				reset();
			}
			glClearColor(0, 0, 0, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			go.renderLoss();
			frameTime = SDL_GetTicks() - frameStart;
		}
		else if (win) {

			if (kbState[SDL_SCANCODE_SPACE]) {
				startscreen = true;
				over = false;
				win = false;
				reset();
			}
			glClearColor(0, 0, 0, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			go.renderWin();
			frameTime = SDL_GetTicks() - frameStart;
		}
		else {
			pd->update(kbState, kbPrevState, projectiles);
			pd->AnimationUpdate(1);

			for (auto& e : enemies) {
				e->update((*pd).getX(), (*pd).getY(), enemies, projectiles, collidables);
			}

			// check projectile collisions
			for (auto& e : projectiles) {
				e->update();
				if (!(e->isActive())) {
					projectiles.remove(e);
				}
				for (auto&c : collidables) {
					if (e->collidedWith(c->getAABB())) {
						c->hit(e->damage);
						e->collisionResolution(c->getAABB());
					}
				}
			}

			// sprite collision
			for (auto& e : enemies) {
				if (pd->collidedWith(e->getAABB())) {
					if (pd->isDescending() && e->getAABB().tag != "spiny") {
						e->hit(1000);
						pd->destroyedEnemy();
						//pd->collisionResolution(e->getAABB());
					}
					else {
						pd->collisionResolution(e->getAABB());
					}
				}
			}

			// background collision
			for (auto &e : collidables) {
				bool nocollision = true;
				for (int i = 2 - e->getAABB().x / bd.getWidth(); i < e->getAABB().x / bd.getWidth() + 6; i++) {
					//if (i < 0) i = 0;
					for (int j = e->getAABB().y / bd.getHeight(); j < e->getAABB().y / bd.getHeight() + 5; j++) {
						if (bd.getTile(j, i).getCollision()) {
							AABB t_box = bd.getTile(j, i).getAABB();
							t_box.y = j * t_box.w;
							t_box.x = i * t_box.h;
							if (e->collidedWith(t_box)) {
								e->collisionResolution(t_box);
								nocollision = false;
							}
							for (auto &p : projectiles) {
								if (p->collidedWith(t_box)) {
									p->active = false;
									projectiles.remove(p);
								}
							}
						}
					}
				}
				if (nocollision && e->isGrounded()) {
					e->setGrounded(false);
				}
				if (e->getAABB().y > 4000 && e->getAABB().tag != "player") collidables.remove(e);
			}

			c.update((*pd).getX(), (*pd).getY());

			if (pd->getLives() <= 0) {
				over = true;
			}
			if (pd->getWin()) {
				win = true;
			}
			else {
				glClearColor(0, 0, 0, 1);
				glClear(GL_COLOR_BUFFER_BIT);

				// Game drawing goes here.

				bd.DrawBackground(c.getX(), c.getY());
				(*pd).render(c.getX(), c.getY());

				for (auto &e : enemies) {
					if (e->isAlive()) {
						e->AnimationUpdate(1);
						e->render(c.getX(), c.getY());
					}
					else {
						enemies.remove(e);
					}
				}

				for (auto &e : projectiles) {
					if (e->isActive()) {
						e->AnimationUpdate(1);
						e->render(c.getX(), c.getY());
					}
				}

				h.render(pd->getLives());

				// Present the most recent frame.
			}
			frameTime = SDL_GetTicks() - frameStart;
		}

		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}

		SDL_GL_SwapWindow(window);
	}

	SDL_Quit();

	return 0;
}
