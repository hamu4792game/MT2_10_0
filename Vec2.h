#pragma once

struct Vec2 {
	float x, y;
};

Vec2 Lerp(const Vec2& a, const Vec2& b, float t);

Vec2 Bezier(const Vec2& p0, const Vec2& p1, const Vec2& p2, float t);

Vec2 Change(const Vec2& pos);