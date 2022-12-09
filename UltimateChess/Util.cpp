#include "Util.h"
#include <math.h>
#include <stdlib.h>

using namespace chess;
using namespace std;

float chess::randFloat(float min, float max) {
	float random = ((float)rand()) / (float)RAND_MAX;

	return (random * (max - min)) + min;
}

int chess::randInt(int min, int max) {
	return rand() % max + min;
}

float chess::to360(float d) {
	float degrees360 = d;

	if (degrees360 > 360.0f) {
		degrees360 = fmodf(degrees360, 360.0f);
	}
	
	if (degrees360 < 0.0f) {
		degrees360 = 360.0f - fmodf(fabsf(degrees360), 360.0f);
	}

	return degrees360;
}

vector<Piece> chess::detectCollision(Piece piece, vector<Piece> pieces)
{
	vector<Piece> collisions;

	for (int i = 0; i < pieces.size(); i++) {
		if (piece.collidesWith(pieces[i])) {
			collisions.emplace_back(pieces[i]);
		}
	}
	return collisions;
}
