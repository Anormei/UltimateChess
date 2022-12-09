#pragma once
#include "Vec2.h"
class Line {
	public:
		Line();
		Line(float x1, float y1, float x2, float y2);
		Line(Vec2 pos1, Vec2 pos2);

		bool intersects(Line line);

	private:
		Vec2 pos1;
		Vec2 pos2;
};