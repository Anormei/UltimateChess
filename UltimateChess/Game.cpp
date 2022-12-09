

#include <iostream>
#include <time.h>
#include "Piece.h"
#include "Queen.h"
#include "Rook.h"
#include "Bishop.h"
#include <vector>
#include "Util.h"

using namespace std;
using namespace chess;

int main(){
	srand(time(NULL));

	vector<Piece> pieces;
	cout << "GAME_START" << endl;

	cout << "Initializing queens...";

	for (int i = 0; i < max_pieces / 3; i++) {
		Queen piece = Queen(randFloat(0, board_size), randFloat(0, board_size));
		cout << "Queen[" << i << "]";
		while (detectCollision(piece, pieces).size() > 0) {
			piece.setPos(randFloat(0, board_size), randFloat(0, board_size));
		}

		pieces.emplace_back(piece);
	}

	cout << "Initializing bishops...";

	for (int i = 0; i < max_pieces / 3; i++) {
		Bishop piece = Bishop(randFloat(0, board_size), randFloat(0, board_size));
		while (detectCollision(piece, pieces).size() > 0) {
			piece.setPos(randFloat(0, board_size), randFloat(0, board_size));
		}

		pieces.emplace_back(piece);
	}

	cout << "Initializing rooks...";

	for (int i = 0; i < max_pieces / 3; i++) {
		Rook piece = Rook(randFloat(0, board_size), randFloat(0, board_size));
		while (detectCollision(piece, pieces).size() > 0) {
			piece.setPos(randFloat(0, board_size), randFloat(0, board_size));
		}

		pieces.emplace_back(piece);
	}

	cout << "Game begins";

	for (int i = 0; i < max_moves && pieces.size() > 1; i++) {
		vector<Piece>::iterator it = pieces.begin();

		cout << "Move[" << i << "]" << endl;

		while (it != pieces.end()) {
			int index = std::distance(pieces.begin(), it);
			cout << "Piece[" << index << "]: " << *it;
			Vec2 move = it->move();
			
			cout << it->name() << " has moved (" << move << ")" << "spaces." << endl;
			vector<Piece> collisions = detectCollision(*it, collisions);
			cout << "Piece[" << index << "] (" << it->name() << ") " << "has captured " << collisions.size() << " pieces." << endl;
			for (int j = 0; j < collisions.size(); j++) {
				it->increaseCapture();
				vector<Piece>::iterator pos = std::find(pieces.begin(), pieces.end(), collisions[i]);
				if (pos != pieces.end()) {
					pieces.erase(pos);
				}
			}

			it = std::next(it, 1);
		}

	}
}