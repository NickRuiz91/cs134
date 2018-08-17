#include "Vector2.h"
#include <cmath>

Vector2::Vector2(void) : x(0), y(0) {}
Vector2::Vector2(float x, float y) : x(x), y(y) {}
Vector2::~Vector2(void) {}

void Vector2::reassign(float x, float y) {
	this->x = x;
	this->y = y;
}

void Vector2::reassign(Vector2 otr) {
	reassign(otr.x, otr.y);
}

Vector2& Vector2::operator+=(const Vector2 otr) {
	this->x += otr.x;
	this->y += otr.y;
	return *this;
}

Vector2& Vector2::operator-=(const Vector2 otr) {
	this->x -= otr.x;
	this->y -= otr.y;
	return *this;
}

Vector2& Vector2::operator*=(float scl) {
	this->x *= scl;
	this->y *= scl;
	return *this;
}

Vector2& Vector2::operator/=(float scl) {
	this->x /= scl;
	this->y /= scl;
	return *this;
}

Vector2 Vector2::operator+(const Vector2 otr) const {
	return Vector2(this->x + otr.x, this->y + otr.y);
}

Vector2 Vector2::operator-(const Vector2 otr) const {
	return Vector2(this->x - otr.x, this->y - otr.y);
}

Vector2 Vector2::operator*(float scl) const {
	return Vector2(this->x * scl, this->y * scl);
}

Vector2 Vector2::operator/(float scl) const {
	return Vector2(this->x / scl, this->y / scl);
}

bool Vector2::operator==(const Vector2 otr) {
	return this->x == otr.x && this->y == otr.y;
}

bool Vector2::operator!=(const Vector2 otr) {
	return !(*this == otr);
}

float Vector2::dot(const Vector2 otr) {
	return this->x * otr.x + this->y * otr.y;
}

Vector2 Vector2::norm() {
	return *this / this->mag();
}

Vector2& Vector2::trunc(float max) {
	if (this->mag() > max)
		this->reassign(this->norm() * max);
	return *this;
}

float Vector2::ang() {
	return std::atan2(this->x, this->y);
}

float Vector2::mag() {
	return std::sqrt(std::pow(this->x, 2) + std::pow(this->y, 2));
}

int Vector2::distance(int x1, int y1, int x2, int y2) {
	return (int)std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));
}
