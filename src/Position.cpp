//
// Created by atsocs on 25/04/2020.
//

#include <cassert>
#include <utility>
#include "Position.h"

Position::Position(int dimension)
		: origin(dimension)
{
	assert(origin.size() == dimension);
}

Position::Position(std::vector<int> origin)
		: origin{std::move(origin)}
{

}

void Position::setRandom()
{
	for (auto &coordinate : origin)
	{
		coordinate = GetRandomValue(0, BOARD_SIZE - 1);
	}
}

bool operator==(const Position &p1, const Position &p2)
{
	return p1.origin == p2.origin;
}
