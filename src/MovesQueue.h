//
// Created by atsocs on 25/04/2020.
//

#ifndef MOVESQUEUE_DEC580497EAF4C64BCD16B3291C2F3A8_H
#define MOVESQUEUE_DEC580497EAF4C64BCD16B3291C2F3A8_H

#include "Vector.h"
#include <queue>
class MovesQueue
{
public:
	MovesQueue();
	bool empty();
	int size();
	Direction front();
	void pop();
	void add(Direction dir);
private:
	Direction lastPushed;
	std::queue<Direction> q;
};
void handleMoveKeys(MovesQueue& moveQueue);


#endif //MOVESQUEUE_DEC580497EAF4C64BCD16B3291C2F3A8_H
