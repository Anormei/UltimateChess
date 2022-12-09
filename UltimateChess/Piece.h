#pragma once

#include "Vec2.h"
#include "Shape.h"
#include <string>
#include <ostream>

namespace chess {
	class Piece {
	public:

		Piece();
		Piece(float x, float y);
		Piece(Vec2 v);
		~Piece();

		void setPos(float x, float y);
		void setPos(Vec2 v);
		void increaseCapture();

		Vec2 getPos() const;
		Shape* getShape() const;
		int getCaptures() const;

		virtual std::string name() const { return ""; };
		virtual Vec2 move() { return Vec2(0, 0); };
		virtual bool collidesWith(Piece piece) const { return false; };

		const Piece operator=(const Vec2& pos);
		
		virtual bool operator==(const Piece& rhs) { return false; };

	protected:
		Vec2* pos;
		Shape* shape;
		int captures;

	};

	std::ostream& operator<<(std::ostream& outStream, const Piece& piece);
}

