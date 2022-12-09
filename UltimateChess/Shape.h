#pragma once
#include "Vec2.h"
class Shape {
	public:

		virtual bool collidesWith(Shape* shape) const = 0;
		void linkPosition(Vec2 &p);

		Vec2 getPos() const;
	protected:
		Vec2* pos;
};