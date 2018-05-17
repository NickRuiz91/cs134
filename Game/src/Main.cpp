#define SDL_MAIN_HANDLED
#define GLEW_STATIC
#include<SDL.h>
#include<GL/glew.h>
#include<string.h>
#include<assert.h>
#include<iostream>
#include"DrawUtils.h"
#include"Player.h"
#include"Background.h"
#include"Camera.h"

// Set this to true to make the game loop exit.
bool shouldExit = false;

// The previous frame's keyboard state.
unsigned char kbPrevState[SDL_NUM_SCANCODES] = { 0 };

// The current frame's keyboard state.
const unsigned char* kbState = NULL;

Camera c;
BackgroundDef bg;

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
		"SDLTemplate",
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
	c.x = 0;
	c.y = 0;

	Player pd;
	BackgroundLoad(&bg);

	unsigned int prevTime;
	unsigned int currentTime = SDL_GetTicks();
	unsigned int deltatime;

	// The game loop.
	kbState = SDL_GetKeyboardState(NULL);
	while (!shouldExit) {
		assert(glGetError() == GL_NO_ERROR);
		memcpy(kbPrevState, kbState, sizeof(kbPrevState));

		prevTime = currentTime;

		// Handle OS message pump.
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT:
				shouldExit = true;
			}
		}

		currentTime = SDL_GetTicks();
		deltatime = currentTime - prevTime;

		// Game logic goes here.
		if (kbState[SDL_SCANCODE_ESCAPE]) {
			shouldExit = true;
		}

		CameraUpdate(&c, kbState[SDL_SCANCODE_A], kbState[SDL_SCANCODE_S], kbState[SDL_SCANCODE_D], kbState[SDL_SCANCODE_W], deltatime, kbState[SDL_SCANCODE_SPACE], pd.getX(), pd.getY());
		pd.update(kbState[SDL_SCANCODE_LEFT], kbState[SDL_SCANCODE_RIGHT], kbState[SDL_SCANCODE_UP], kbState[SDL_SCANCODE_DOWN], deltatime);
		pd.AnimationUpdate(deltatime);

		glClearColor(0, 0, 0, 1);
		glClear(GL_COLOR_BUFFER_BIT);

		for (int i = c.x / bg.width; i < c.x / bg.width + 36; i++) {
			for (int j = c.y / bg.height; j < c.y / bg.height +20; j++) {
				glDrawSprite(bg.tiles[i][j], bg.width * i - c.x, bg.height * j - c.y, bg.width, bg.height);
			}
		}

		// Game drawing goes here.
		if (pd.onscreen(c.x, c.y)) glDrawSprite(pd.getImage(), pd.getX() - c.x, pd.getY() - c.y, pd.getXSize(), pd.getYSize(), pd.getReverse());

		// Present the most recent frame.
		SDL_GL_SwapWindow(window);
	}

	SDL_Quit();

	return 0;
}
