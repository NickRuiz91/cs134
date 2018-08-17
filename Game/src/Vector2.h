#pragma once

class Vector2 {
public:
	float x;
	float y;
	Vector2(void);
	Vector2(float, float);
	~Vector2(void);
	Vector2& operator+=(const Vector2);
	Vector2 operator+(const Vector2) const;
	Vector2& operator-=(const Vector2);
	Vector2 operator-(const Vector2) const;
	Vector2& operator*=(float);
	Vector2 operator*(float) const;
	Vector2& operator/=(float);
	Vector2 operator/(float) const;
	bool operator==(const Vector2);
	bool operator!=(const Vector2);
	float dot(const Vector2);
	Vector2 norm();
	Vector2& trunc(float);
	float ang();
	float mag();
	void reassign(float, float);
	void reassign(Vector2);
	static int distance(int x1, int y1, int x2, int y2);
};
