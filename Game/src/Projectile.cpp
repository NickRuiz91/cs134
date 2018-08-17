#include "Projectile.h"
#include"DrawUtils.h"

void Projectile::render(int camx, int camy) {
	if (active && GameObject::onscreen(position.x, position.y, getXSize(), getYSize(), scale, camx, camy)) {
		glDrawSprite(getImage(), position.x - camx, position.y - camy, getXSize() * scale, getYSize() * scale, getReverse());
	}
}
