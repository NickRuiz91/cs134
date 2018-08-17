#include"Collision.h"

bool Collision::collidedWith(AABB box2) {
	if (box.x + box.w >= box2.x && box2.x + box2.w >= box.x && box.y + box.h >= box2.y && box2.y + box2.h >= box.y) return true;
	return false;
}

bool Collision::collided(float box1x, float box1y, float box1h, float box1w, float box2x, float box2y, float box2h, float box2w) {
	if (box1x + box1w >= box2x && box2x + box2w >= box1x && box1y + box1h >= box2y && box2y + box2h >= box1y) return true;
	return false;
}
