#pragma once

#include "Vec2.h"
#include "Shape.h"

class Square : public Shape{
	public:
		Square();
		Square(float left, float up, float right, float down);

		bool collidesWith(Shape* shape) const;

		void set(float left, float up, float right, float down);

		float getLeft() const;
		float getUp() const;
		float getRight() const;
		float getDown() const;

	private:
		float left;
		float up;
		float right;
		float down;
};
