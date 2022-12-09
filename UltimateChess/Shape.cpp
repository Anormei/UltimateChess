#include "Shape.h"


void Shape::linkPosition(Vec2& p)
{
	pos = &p;
}

Vec2 Shape::getPos() const{
	return *pos;
}
