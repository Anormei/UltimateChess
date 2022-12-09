#include "Piece.h"
#include <iostream>

using namespace chess;
using namespace std;

Piece::Piece()
{
	pos = new Vec2(0, 0);
	shape = nullptr;
}

Piece::Piece(float x, float y)
{
	pos = new Vec2(x, y);
	shape = nullptr;
}

Piece::Piece(Vec2 v)
{
	pos = new Vec2(v);
	shape = nullptr;
}

Piece::~Piece()
{
	if (pos != nullptr) {
		delete pos;
		pos = nullptr;
	}

	cout << "Destructor called???";
	if (shape != nullptr) {
		delete shape;
		shape = nullptr;
	}
}

void Piece::setPos(float x, float y)
{
	this->pos->x = x;
	this->pos->y = y;
}

void Piece::setPos(Vec2 v)
{
	this->pos->set(v.x, v.y);
}

void Piece::increaseCapture()
{
	captures++;
}

Vec2 Piece::getPos() const
{
	return Vec2();
}

Shape* Piece::getShape() const
{
	return shape;
}

int Piece::getCaptures() const
{
	return captures;
}


const Piece Piece::operator=(const Vec2& pos)
{
	return Piece(pos);
}

std::ostream& chess::operator<<(std::ostream& outStream, const Piece& piece)
{
	string name = piece.name();
	outStream << piece.name() << ": " << "pos(" << piece.getPos() << ")" << "; total captures = " << piece.getCaptures();

	return outStream;
}
