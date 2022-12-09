#pragma once
#include "Vec2.h"
#include "Shape.h"

class Circle : public Shape{
	public:

		Circle();
		Circle(float radius);

		bool collidesWith(Shape* shape) const;

		void set(float radius);
		float getRadius() const;

	private:
		float radius;
};
