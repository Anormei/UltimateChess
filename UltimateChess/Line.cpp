#include "Line.h"

Line::Line()
{

}

Line::Line(float x1, float y1, float x2, float y2)
{
	pos1 = Vec2(x1, y1);
	pos2 = Vec2(x2, y2);
}

Line::Line(Vec2 pos1, Vec2 pos2)
{
	this->pos1 = pos1;
	this->pos2 = pos2;
}

bool Line::intersects(Line line)
{
	return (((pos2.x - pos1.x) * (line.pos1.y - pos1.y) - (pos2.y - pos1.y) * (line.pos1.x - pos1.x))
		* ((line.pos2.x - pos1.x) * (line.pos1.y - pos1.y) - (line.pos2.y - pos1.y) * (line.pos1.x - pos1.x)) < 0)
		&&
		(((pos1.x - pos2.x) * (line.pos2.y - pos2.y) - (pos1.y - pos2.y) * (line.pos2.x - pos2.x))
			* ((line.pos1.x - pos2.x) * (line.pos2.y - pos2.y) - (line.pos1.y - pos2.y) * (line.pos2.x - pos2.x)) < 0);
}
