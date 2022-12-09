#pragma once

#include "Piece.h"

namespace chess {
	class Bishop : public Piece {
	public:
		const float max_distance = 5.9f;

		Bishop();
		Bishop(float x, float y);
		Bishop(Vec2 v);
		
		std::string name();
		Vec2 move();
		bool collidesWith(Piece piece);

		bool operator==(const Piece& rhs);

	private:
		void init();
	};
}