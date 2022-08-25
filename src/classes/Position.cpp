//
// Created by atsocs on 25/04/2020.
//

#include "../Okay.h"
#include "Position.h"

#include <cassert>
#include <iomanip>
#include <utility>

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

std::ostream &operator<<(std::ostream &os, const Position &position)
{
	static const int digits = numDigits(BOARD_SIZE - 1);
	os << '[';
	assert(position.origin.size() == DIMENSION);
	for (int index{0}; index < position.origin.size(); ++index)
	{
		os << std::setw(digits) << position.origin[index];
		if (index + 1 != position.origin.size())
		{ os << ' '; }
	}
	os << ']';
	return os;
}