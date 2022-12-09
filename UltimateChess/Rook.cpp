#include "Rook.h"
#include "Util.h"
#include "Square.h"

using namespace chess;

Rook::Rook() : Piece()
{
	init();
}

Rook::Rook(float x, float y) : Piece(x, y)
{
	init();
}

Rook::Rook(Vec2 v) : Piece(v)
{
	init();
}

std::string Rook::name()
{
	return "Rook";
}

Vec2 Rook::move()
{
	Vec2 travel;
	do {
		travel = Vec2(randFloat(0, max_distance), 0);
		travel.rotate(randFloat(0, (straight + next_angle) * randInt(0, 4)));
	} while ((*pos + travel).x > board_size || (*pos + travel).y > board_size);
	*pos += travel;
	return travel;
}

bool Rook::collidesWith(Piece piece)
{
	return shape->collidesWith(piece.getShape());
}

bool chess::Rook::operator==(const Piece& rhs)
{
	if (typeid(rhs) != typeid(Rook)) {
		return false;
	}

	return this->getPos() == rhs.getPos();
}

void Rook::init()
{

	shape = new Square(0, 0, 2.0f, 2.0f);
	shape->linkPosition(*pos);
}
