#include "Vec2.h"

Vec2 Lerp(const Vec2& a, const Vec2& b, float t) {
	Vec2 result;
	result.x = t * a.x + (1.0f - t) * b.x;
	result.y = t * a.y + (1.0f - t) * b.y;
	return result;
}

Vec2 Bezier(const Vec2& p0, const Vec2& p1, const Vec2& p2, float t) {
	Vec2 result;
	result = Lerp(Lerp(p0, p1, t), Lerp(p1, p2, t), t);
	return result;
}

Vec2 CatmullRom(const Vec2& p0, const Vec2& p1, const Vec2& p2, const Vec2& p3, float t) {
	Vec2 result;
	result.x = (((-p0.x) + (3 * p1.x) - (3 * p2.x) + (p3.x)) * (t * t * t)
		+ ((2 * p0.x) - (5 * p1.x) + (4 * p2.x) - (p3.x)) * (t * t)
		+ ((-p0.x) + (p2.x)) * t
		+ 2 * (p1.x)) / 2;
	result.y = (((-p0.y) + (3 * p1.y) - (3 * p2.y) + (p3.y)) * (t * t * t)
		+ ((2 * p0.y) - (5 * p1.y) + (4 * p2.y) - (p3.y)) * (t * t)
		+ ((-p0.y) + (p2.y)) * t
		+ 2 * (p1.y)) / 2;
	return result;
}

Vec2 Change(const Vec2& pos) {
	Vec2 result;
	result.x = pos.x + 200.0f;
	result.y = (pos.y * -1) + 520.0f;
	return result;
}