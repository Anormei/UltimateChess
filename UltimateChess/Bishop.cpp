#include "Bishop.h"
#include "Util.h"
#include "Circle.h"

using namespace chess;

Bishop::Bishop() : Piece()
{
	init();
}

Bishop::Bishop(float x, float y) : Piece(x, y)
{
	init();
}

Bishop::Bishop(Vec2 v) : Piece(v)
{
	init();
}

std::string Bishop::name()
{
	return "Bishop";
}

Vec2 Bishop::move()
{
	Vec2 travel;
	do {
		travel = Vec2(randFloat(0, max_distance), 0);
		float angle = to360(randFloat(0, (diagonal + next_angle) * randInt(0, 4)));
		travel.rotate(angle);
	} while ((*pos + travel).x > board_size || (*pos + travel).y > board_size);
	*pos += travel;
	return travel;
}

bool Bishop::collidesWith(Piece piece)
{
	return false;
}

bool Bishop::operator==(const Piece& rhs)
{

	if (typeid(rhs) != typeid(Bishop)) {
		return false;
	}

	return this->getPos() == rhs.getPos();
}

void Bishop::init()
{

	shape = new Circle(1.0f);
	shape->linkPosition(*pos);
}
