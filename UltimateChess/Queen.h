#pragma once

#include "Piece.h"

namespace chess {
	class Queen : public Piece {

	public:
		const float max_distance = 9.9f;

		Queen();
		Queen(float x, float y);
		Queen(Vec2 v);

		std::string name();
		Vec2 move();
		bool collidesWith(Piece piece) const;

		bool operator==(const Piece& rhs);

	private:
		void init();
	};
}