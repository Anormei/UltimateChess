#include "Queen.h"
#include "Util.h"
#include "Circle.h"

using namespace chess;

Queen::Queen() : Piece()
{
	init();
}

Queen::Queen(float x, float y) : Piece(x, y)
{
	init();
}

Queen::Queen(Vec2 v) : Piece(v)
{
	init();
}

void Queen::init() {

	shape = new Circle(1.0f);
	shape->linkPosition(*pos);
}

std::string Queen::name()
{
	return "Queen";
}

Vec2 Queen::move()
{

	Vec2 travel;
	do {
		travel = Vec2(randFloat(0, max_distance), 0);
		travel.rotate(randFloat(0, (next_angle / 2.0f) * randInt(0, 8)));
	} while ((*pos + travel).x > board_size || (*pos + travel).y > board_size);
	*pos += travel;
	return travel;
}

bool Queen::collidesWith(Piece piece) const
{
	return shape->collidesWith(piece.getShape());
}

bool chess::Queen::operator==(const Piece& rhs)
{
	if (typeid(rhs) != typeid(Queen)) {
		return false;
	}

	return this->getPos() == rhs.getPos();
}
