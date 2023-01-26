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

Vec2 Change(const Vec2& pos) {
	Vec2 result;
	result.x = pos.x + 200.0f;
	result.y = (pos.y * -1) + 520.0f;
	return result;
}