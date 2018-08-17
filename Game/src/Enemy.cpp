#include"Enemy.h"

void Enemy::render(int camx, int camy) {
		if (alive && GameObject::onscreen(position.x, position.y, getXSize(), getYSize(), scale, camx, camy)) {
			glDrawSprite(getImage(), position.x - camx, position.y - camy, getXSize() * scale, getYSize() * scale, getReverse());
		}
}
