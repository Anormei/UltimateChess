#include "Square.h"
#include <typeinfo>
#include "Line.h"
#include "Circle.h"

Square::Square()
{
	left = 0;
	up = 0;
	right = 0;
	down = 0;
}

Square::Square(float left, float up, float right, float down)
{
	this->left = left;
	this->up = up;
	this->right = right;
	this->down = down;
}

bool Square::collidesWith(Shape* shape) const
{
	Square* square;
	Circle* circle;

	if (typeid(*shape) == typeid(Square)) {
		square = dynamic_cast<Square*>(shape);
		return (pos->x + left) <= (square->pos->x + square->right) && 
			(pos->y + up) >= (square->pos->x + square->down) && 
			(pos->x + right) >= (square->pos->x + square->left) && 
			(pos->y + down )<= (square->pos->x + square->up);
	}
	else if (typeid(*shape) == typeid(Circle)) {
		circle = dynamic_cast<Circle*>(shape);

		Line line_top = Line(left, up, right, up);
		Line line_right = Line(right, up, right, down);
		Line line_bottom = Line(right, down, left, down);
		Line line_left = Line(left, down, left, up);

		Vec2 pos1 = circle->getPos();
		Vec2 pos2 = Vec2(circle->getPos().x + circle->getRadius(), circle->getPos().y);

		Vec2 mid = Vec2(pos->x + ((right - left) / 2.0f), pos->y + ((down - up) / 2.0f));
		
		Vec2 direction = pos1 - mid;

		float angle = direction.angle();

		pos2.rotate(angle);

		Line line_circle = Line(pos1, pos2);

		return line_circle.intersects(line_top) || line_circle.intersects(line_right) || line_circle.intersects(line_bottom) || line_circle.intersects(line_left);
	}
	return false;
}

void Square::set(float left, float up, float right, float down)
{
	this->left = left;
	this->up = up;
	this->right = right;
	this->down = down;
}

float Square::getLeft() const
{
	return left;
}

float Square::getUp() const
{
	return up;
}

float Square::getRight() const
{
	return right;
}

float Square::getDown() const
{
	return down;
}
