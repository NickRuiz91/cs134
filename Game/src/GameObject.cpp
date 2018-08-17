#include"GameObject.h"

bool GameObject::onscreen(int sprx, int spry, int width, int height, int scale, int camx, int camy) {
	if (sprx + width * scale < camx) return 0;
	if (spry + height * scale < camy) return 0;
	if (sprx > camx + 800) return 0;
	if (spry > camy + 600) return 0;
	return 1;
}
