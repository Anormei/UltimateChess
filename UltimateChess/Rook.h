#pragma once

#include "Piece.h"

namespace chess {
	class Rook : public Piece{
	public:
		const float max_distance = 5.9f;

		Rook();
		Rook(float x, float y);
		Rook(Vec2 v);

		std::string name();
		Vec2 move();
		bool collidesWith(Piece piece);

		bool operator==(const Piece& rhs);

	private:
		void init();
	};
}