#include "Circle.h"
#include <math.h>
#include <typeinfo>
#include "Line.h"
#include "Square.h"

Circle::Circle()
{
	radius = 0;
}

Circle::Circle(float radius)
{
	this->radius = radius;
}

bool Circle::collidesWith(Shape* shape) const
{
	Circle* circle;
	Square* square;

	if (typeid(*shape) == typeid(Circle)) {
		circle = dynamic_cast<Circle*>(shape);
		Vec2 v = Vec2(*pos - *circle->pos);
		return powf(v.x + v.y, 2) <= powf(radius + circle->radius, 2);
	}
	else if (typeid(*shape) == typeid(Square)) {
		square = dynamic_cast<Square*>(shape);

		Line line_top = Line(square->getLeft(), square->getUp(), square->getRight(), square->getUp());
		Line line_right= Line(square->getRight(), square->getUp(), square->getRight(), square->getDown());
		Line line_bottom = Line(square->getRight(), square->getDown(), square->getLeft(), square->getDown());
		Line line_left = Line(square->getLeft(), square->getDown(), square->getLeft(), square->getUp());

		Vec2 pos1 = *pos;
		Vec2 pos2 = Vec2(pos->x + radius, pos->y);

		Vec2 mid = Vec2(square->getPos().x + ((square->getRight() - square->getLeft()) / 2.0f), square->getPos().y + ((square->getDown() - square->getUp()) / 2.0f));

		Vec2 direction = pos1 - mid;

		float angle = direction.angle();

		pos2.rotate(angle);

		Line line_circle = Line(pos1, pos2);

		return line_circle.intersects(line_top) || line_circle.intersects(line_right) || line_circle.intersects(line_bottom) || line_circle.intersects(line_left);
	}
	return false;
}

void Circle::set(float radius)
{
	this->radius = radius;
}

float Circle::getRadius() const
{
	return radius;
}

